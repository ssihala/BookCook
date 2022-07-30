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
        const int HASH_FACTOR=31;
        float const MAX_LOADFACTOR=0.75;
        std::vector<Book> hashtable;
    public:
        Hashtable();
        int hashFunction(int key) const;
        int hashFunction(std::string key) const;
        void expandTable();
        void insertKey(std::vector<Book>& table, int key, Book& value) const;
        void insertKey(int key, Book& value);
        Book searchKey(int key);
        std::vector<int> getRecommendations(int key);
        void updateGenres(int key, std::vector<std::string>& bookGenres);
        std::vector<int> searchByGenre(const std::string& genre);

};


