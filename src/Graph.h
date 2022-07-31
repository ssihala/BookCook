//
// Created by sihala on 7/24/22.
//

#pragma once

#include <vector>
#include <unordered_map>
#include "book.h"


class Graph {
    private:
        //Adjacency List: Key:Book Title, Value: pair<Book object, vector of recommended books(IDs) by readers>
        std::unordered_map<std::string, std::pair<Book, std::vector<int>>> adjList;
        //Helper map used to retrieve titles based on book IDs
        std::unordered_map<int, std::string> idMapping;
        int numBooks=0;
    public:
        //Inserts "from" book into graph, and creates an edge with "to"
        void insertEdge(Book& from, int to);
        Book searchID(const std::string& title);
        std::vector<std::string> getAdjacents(const std::string& title);
        //Called after all edges are inserted into graph
        void loadIDMapping();

};



