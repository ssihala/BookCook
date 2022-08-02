#include "book.h"
#include "Graph.h"
#include "hashtable.h"
#include "SpeedTests.h"
#include "Input.h"

#include <iostream>

int main(){

    

    std::cin.clear();
    int input = 1;

    while (input != 0){
        std::cout << "1: Enter Book" << std::endl;
        std::cout << "2: Graph vs Hashtable Speed Comparison" << std::endl;
        std::cout << "0: Exit" << std::endl; 
        std::cin >> input; 

        std::string bookName;
        Graph graph;
        Hashtable hash;
        std::unordered_map<int, std::string> idMap;
        int numElements;
        switch (input){
            case 1:
                std::cin.ignore();
                getline(std::cin, bookName);
                loadHash(hash,idMap);
                if (hash.searchKey(bookName).id == -1) // if book isn't in table
                    std::cout << "Book not found" << std::endl << std::endl;
                else {
                    Book result = hash.searchKey(bookName);
                    if(result.similarBooks.empty())
                        std::cout << "Sorry, no recommended books found in dataset" << std::endl;
                    else{
                        std::cout << "RECOMMENDATIONS: " << std::endl;
                        for (int & similarBook : result.similarBooks){
                            if(idMap.find(similarBook) != idMap.end())
                                std::cout << idMap.at(similarBook) << std::endl;
                        }
                        std::cout << std::endl; // spacing
                    }
                }
                break; 
            case 2:
                std::cout << "Enter Number of Elements to be Tested: " << std::endl;
                std::cin >> numElements; 
                insertionTest(hash, graph, numElements);
                searchTest(hash, graph);
                break;
            case 0: 
                break; 
            default:
                std::cout << "Invalid Input" << std::endl; 
        }
    }

    return 0;
}
