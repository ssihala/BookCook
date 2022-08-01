//
// Created by sihala on 7/20/22.
//

#pragma once
#include<vector>
#include "book.h"

class Hashtable {
    private:
        int numKeys;
        //CHOOSE GOOD PRIME NUMBER- referenced from https://www.planetmath.org/goodhashtableprimes, hashtable will be doubled to accommodate all 2.3 million books.
        int numBuckets;
        //const int HASH_FACTOR=31;
        float const MAX_LOADFACTOR=0.75;
        std::vector<Book> hashtable;
    public:
        Hashtable();
        int hashFunction(std::string key) const;
        void expandTable();
        void insertKey(std::vector<Book>& table, std::string key, Book& value) const;
        void insertKey(std::string key, Book& value);
        Book searchKey(const std::string& key);
        std::vector<int> getRecommendations(const std::string& title);
        void updateGenres(std::string title, std::vector<std::string>& bookGenres);
        std::vector<int> searchByGenre(const std::string& genre);

};


