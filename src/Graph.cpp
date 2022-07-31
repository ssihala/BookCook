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

std::vector<std::string> Graph::getAdjacents(const std::string& title) {
    std::vector<std::string> adjacents;
    for(int element : adjList[title].second)
        adjacents.push_back(idMapping[element]);

    return adjacents;
}

void Graph::loadIDMapping() {
    for(auto it = adjList.begin(); it != adjList.end(); it++)
        idMapping[it->second.first.id] = it->first;
}
