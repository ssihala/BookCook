//
// Created by sihala on 7/24/22.
//

#pragma once

#include <vector>
#include <unordered_map>
#include "book.h"


class Graph {
    private:
        //Adjacency List: Key:BookID, Value: pair<Book object, vector of recommended books(IDs) by readers>
        std::unordered_map<int, std::pair<Book, std::vector<int>>> adjList;
        int numBooks=0;
    public:
        //Inserts "from" book into graph, and creates an edge with "to"
        void insertEdge(Book& from, int to);
        Book searchID(int id);
        std::vector<Book> getAdjacents(int id);

};



