//
// Created by sihala on 7/20/22.
//

#include "hashtable.h"
#include <cmath>
Hashtable::Hashtable() {
    numKeys=0;
    numBuckets=1572869;
    hashtable.resize(numBuckets);
}

int Hashtable::hashFunction(int key) const {
    return key%numBuckets;
}

int Hashtable::hashFunction(std::string key) const {
    int hash=0;
    //Overflow avoided using properties of modulus operator
    for(int i=0; i<key.length(); i++){
        hash += std::pow(HASH_FACTOR, i) * key[i];
        hash = hash%numBuckets;
    }
    return hash%numBuckets;
}

void Hashtable::expandTable() {
    std::vector<Book> newTable;
    newTable.resize(numBuckets*2);
    numBuckets*=2;

    for(Book element : hashtable)
        if(element.id != -1)
            insertKey(newTable, element.id, element);

    hashtable = newTable;
}

void Hashtable::insertKey(int key, Book& value) {
    int index= hashFunction(key);
    numKeys++;
    if(hashtable[index].id==-1)
        hashtable[index]=value;
    else{
        //COLLISION RESOLUTION-QUADRATIC PROBING
        for(int i=0; i<numBuckets; i++){
            if(hashtable[(index + i*i)%numBuckets].id== -1){
                hashtable[(index + i*i)%numBuckets]=value;
                break;
            }
        }
    }

    if((float)numKeys/(float)numBuckets > MAX_LOADFACTOR)
        expandTable();
}

void Hashtable::insertKey(std::vector<Book> &table, int key, Book &value) const {
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
        for(int i=0; i<numBuckets; i++){
            if(hashtable[(index + i*i)%numBuckets].id== -1){
                hashtable[(index + i*i)%numBuckets]=value;
                break;
            }
        }
    }

    if((float)numKeys/(float)numBuckets > MAX_LOADFACTOR)
        expandTable();
}

Book Hashtable::searchKey(int key) {
    int index = hashFunction(key);
    if(hashtable[index].id == key)
        return hashtable[index];
    else{
        for(int i=0; i<numBuckets; i++){
            if(hashtable[(index + i*i)%numBuckets].id== key){
                return hashtable[(index + i*i)%numBuckets];
            }
        }
    }

    Book notFound;
    return notFound;
}

std::vector<int> Hashtable::getRecommendations(int key) {
    return searchKey(key).similarBooks;
}

void Hashtable::updateGenres(int key, std::vector<std::string> &bookGenres) {
    int index = hashFunction(key);
    hashtable[index].genres = bookGenres;
}

std::vector<int> Hashtable::searchByGenre(const std::string& genre) {
    std::vector<int> ids;
    for(const auto& book : hashtable){
        for(const auto& element : book.genres)
            if(element == genre)
                ids.push_back(book.id);
    }

    return ids;
}

