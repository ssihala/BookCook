//
// Created by sihala on 8/1/22.
//

#include "SpeedTests.h"

void insertionTest(Hashtable& hash, Graph& graph, int num) {
    //Reference: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

    int numElements=num;


    auto hashBegin = std::chrono::high_resolution_clock::now();

    Book tolstoy;
    tolstoy.title = "War and Peace";
    std::vector<int> adj = {1,2,3,4,5};
    tolstoy.similarBooks = adj;

    for(int i=1; i<numElements; i++){
        Book tmp;
        tmp.title = std::to_string(i);
        tmp.similarBooks = adj;
        hash.insertKey(tmp.title, tmp);
    }
    hash.insertKey(tolstoy.title, tolstoy);
    auto hashEnd = std::chrono::high_resolution_clock::now();

    auto hashInsertion = std::chrono::duration_cast<std::chrono::milliseconds>(hashEnd - hashBegin);



    auto graphBegin = std::chrono::high_resolution_clock::now();
    tolstoy;
    tolstoy.title = "War and Peace";
    adj = {1,2,3,4,5};
    tolstoy.similarBooks = adj;
    for(int i=1; i<numElements; i++){
        Book tmp;
        tmp.title = std::to_string(i);
        tmp.similarBooks = adj;
        for(int element : tmp.similarBooks)
            graph.insertEdge(tmp, element);
    }
    auto graphEnd = std::chrono::high_resolution_clock::now();

    auto graphInsertion = std::chrono::duration_cast<std::chrono::milliseconds>(graphEnd - graphBegin);

    std::cout << "Inserting " << numElements << " elements into the hash table takes " << hashInsertion.count() << " milliseconds while graph insertion takes " << graphInsertion.count() << " milliseconds."<< std::endl;
};

void searchTest(Hashtable& hash, Graph& graph){
    std::string title = "War and Peace";

    auto hashBegin = std::chrono::high_resolution_clock::now();
    hash.searchKey(title);
    auto hashEnd = std::chrono::high_resolution_clock::now();

    auto hashSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(hashEnd - hashBegin);

    auto graphBegin = std::chrono::high_resolution_clock::now();
    graph.searchID(title);
    auto graphEnd = std::chrono::high_resolution_clock::now();

    auto graphSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(graphEnd - graphBegin);

    std::cout << "Searching for title \"" << title << "\" in the hash table takes " << hashSearch.count() << " nanoseconds while graph search takes " << graphSearch.count() << " nanoseconds."<< std::endl;



}


