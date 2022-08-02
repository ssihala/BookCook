//
// Created by sihala on 7/20/22.
//

#include "hashtable.h"
#include <cmath>
Hashtable::Hashtable() {
    numKeys=0;
    numBuckets=98317;
    hashtable.resize(numBuckets);
}

int Hashtable::hashFunction(std::string key) const {
    int hash=0;
    //Overflow avoided using properties of modulus operator
    for(int i=0; i<key.length(); i++){
        hash += key[i];
        hash = hash%numBuckets;
    }
    if(hash < 0)
        hash += numBuckets;

    return hash%numBuckets;
}

void Hashtable::expandTable() {
    std::vector<Book> newTable;
    newTable.resize(numBuckets*2);
    numBuckets*=2;

    for(Book element : hashtable)
        if(element.id != -1)
            insertKey(newTable, element.title, element);

    hashtable = newTable;
}

void Hashtable::insertKey(std::vector<Book> &table, std::string key, Book &value) const {
    int index= hashFunction(key);
    if(table[index].id==-1)
        table[index]=value;
    else{
        //COLLISION RESOLUTION-QUADRATIC PROBING
        for(int i=0; i<numBuckets; i++){
            if(table[(index + i*i)%numBuckets].id== -1){
                table[(index + i*i)%numBuckets]=value;
                break;
            }
        }
    }
}

void Hashtable::insertKey(std::string key, Book &value) {
    int index= hashFunction(key);
    numKeys++;
    if(hashtable[index].id==-1)
        hashtable[index]=value;
    else{
        //COLLISION RESOLUTION-QUADRATIC PROBING
        int i=1;
        while(i!=0){
            if(hashtable[(index + i*i)%numBuckets].id== -1){
                hashtable[(index + i*i)%numBuckets]=value;
                break;
            }
            i++;
        }
    }

    if((float)numKeys/(float)numBuckets > MAX_LOADFACTOR)
        expandTable();
}

Book Hashtable::searchKey(const std::string& key) {
    int index = hashFunction(key);
    if(hashtable[index].title == key)
        return hashtable[index];
    else{
        int i=0;
        while(i!=0){
            if(hashtable[(index + i*i)%numBuckets].title== key){
                return hashtable[(index + i*i)%numBuckets];
            }
            i++;
        }
    }

    Book notFound;
    return notFound;
}

std::vector<int> Hashtable::getRecommendations(const std::string& title) {
    return searchKey(title).similarBooks;
}

//void Hashtable::updateGenres(std::string title, std::vector<std::string> &bookGenres) {
//    int index = hashFunction(std::move(title));
//    hashtable[index].genres = bookGenres;
//}

//std::vector<int> Hashtable::searchByGenre(const std::string& genre) {
//    std::vector<int> ids;
//    for(const auto& book : hashtable){
//        for(const auto& element : book.genres)
//            if(element == genre)
//                ids.push_back(book.id);
//    }
//
//    return ids;
//}

