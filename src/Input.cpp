//
// Created by sihala on 8/1/22.
//

#include "Input.h"
#include  <fstream>
#include "book.h"
#include <iostream>

using json = nlohmann::json;

void loadHash(Hashtable& hash, std::unordered_map<int, std::string>& idMapping){
    std::ifstream file("childrens_trimmed.json");
    bool fileEnd = false;
    json data;
    std::string tmpString;
    file >> data;
    for(auto element : data){
        Book tmp;
        tmp.isbn = element["isbn"];
        tmp.title = element["title"];
        tmpString = element["average_rating"];
        if(!tmpString.empty())
            tmp.avgRating = std::stod(tmpString);

        tmp.publisher = element["publisher"];

        tmpString = element["num_pages"];
        if(!tmpString.empty())
            tmp.numPages = std::stoi(tmpString);

        tmpString = element["publication_year"];
        if(!tmpString.empty())
            tmp.publicationYear = std::stoi(tmpString);

        tmpString = element["book_id"];
        if(!tmpString.empty())
            tmp.id = std::stoi(tmpString);

        if(!element["similar_books"].empty()){
            for(const auto& recommend : element["similar_books"]){
                tmpString = recommend;
                if(!tmpString.empty() && tmp.similarBooks.size() <5)
                    tmp.similarBooks.push_back(std::stoi(tmpString));
            }
        }

        idMapping[tmp.id] = tmp.title;
        hash.insertKey(tmp.title, tmp);
    }
    }

void loadGraph(Graph& graph){
    std::ifstream file("childrens_trimmed.json");
    bool fileEnd = false;
    json data;
    std::string tmpString;
    file >> data;

    for(auto element : data){
        Book tmp;
        tmp.isbn = element["isbn"];
        tmp.title = element["title"];
        tmpString = element["average_rating"];
        if(!tmpString.empty())
            tmp.avgRating = std::stod(tmpString);

        tmp.publisher = element["publisher"];

        tmpString = element["num_pages"];
        if(!tmpString.empty())
            tmp.numPages = std::stoi(tmpString);

        tmpString = element["publication_year"];
        if(!tmpString.empty())
            tmp.publicationYear = std::stoi(tmpString);

        tmpString = element["book_id"];
        if(!tmpString.empty())
            tmp.id = std::stoi(tmpString);

        if(!element["similar_books"].empty()){
            for(const auto& recommend : element["similar_books"]){
                tmpString = recommend;
                if(tmp.similarBooks.size() <5){
                    int toID = std::stoi(tmpString);
                    tmp.similarBooks.push_back(toID);
                    graph.insertEdge(tmp, toID);
                }
            }
        }
        else{
            graph.insertEdge(tmp, -1);
        }
    }
    graph.loadIDMapping();
}



