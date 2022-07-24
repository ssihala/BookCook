//
// Created by sihala on 7/24/22.
//

#include "Graph.h"

void Graph::insertEdge(Book &from, int to) {
    if(adjList.find(from.id) == adjList.end()){
        adjList[from.id].first = from;
        numBooks++;
    }

    adjList[from.id].second.push_back(to);

}

Book Graph::searchID(int id) {
    if(adjList.find(id) != adjList.end())
        return adjList[id].first;
    else{
        Book null;
        return null;
    }
}

std::vector<Book> Graph::getAdjacents(int id) {
    std::vector<Book> adjacents;

    for(auto element : adjList[id].second){
        adjacents.push_back(adjList[element].first);
    }

    return adjacents;
}
