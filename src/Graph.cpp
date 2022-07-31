//
// Created by sihala on 7/24/22.
//

#include "Graph.h"

//If a book happens to have no adjacents, function is called with -1 as the to vertex
void Graph::insertEdge(Book &from, int to) {
    if(adjList.find(from.title) == adjList.end()){
        adjList[from.title].first = from;
        numBooks++;
    }

    adjList[from.title].second.push_back(to);

}

Book Graph::searchID(const std::string& title) {
    if(adjList.find(title) != adjList.end())
        return adjList[title].first;
    else{
        Book null;
        return null;
    }
}

std::vector<int> Graph::getAdjacents(const std::string& title) {
    return adjList[title].second;
}

void Graph::loadIDMapping() {
    for(auto it = adjList.begin(); it != adjList.end(); it++)
        idMapping[it->second.first.id] = it->first;
}
