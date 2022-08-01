//
// Created by sihala on 8/1/22.
//

#include "Input.h"
#include  <fstream>
#include "book.h"
#include <iostream>

using json = nlohmann::json;

void loadHash(Hashtable& hash){
    std::ifstream file("goodreads_books_poetry.json");
    bool fileEnd = false;
    json data;
    //file >> data;
    Book tmp;
    std::string tmpString;
    double tmpDouble;
    int tmpInt;
    std::vector<std::string> tmpVec;
    std::vector<int> tmpIntVec;

    /*
    while(!fileEnd){
        try{
            data.clear();
            file >> data;
        }
        catch(json::parse_error& excp){
            //std::cout << "EXCEPTION";
            fileEnd = true;
            break;
        }

        tmpVec.clear();
        tmpIntVec.clear();
        tmpString.clear();

        if(data.contains("isbn"))
            tmp.isbn = data["isbn"];

        if(data.contains("title"))
                tmp.title = data["title"];

        if(data.contains("average_rating")){
            tmpString = data["average_rating"];
            if(!tmpString.empty())
                tmp.avgRating = std::stod(tmpString);
        }

        if(data.contains("similar_books")){
            for(const auto& element : data["similar_books"]){
                tmpString = element;
                if(!tmpString.empty())
                    tmp.similarBooks.push_back(std::stoi(tmpString));
            }
        }

        if(data.contains("description"))
            tmp.description = data["description"];

        if(data.contains("link"))
            tmp.url = data["link"];

        if(data.contains("authors"))
            for(auto element : data["authors"]){
                tmpString = element["author_id"];
                if(!tmpString.empty())
                    tmp.authors.push_back(tmpString);
            }

        if(data.contains("publisher"))
            tmp.publisher = data["publisher"];

        if(data.contains("num_pages")){
            tmpString = data["num_pages"];
            if(!tmpString.empty())
                tmp.numPages = std::stoi(tmpString);
        }

        if(data.contains("publication_year")){
            tmpString = data["publication_year"];
            if(!tmpString.empty())
                tmp.publicationYear = std::stoi(tmpString);
        }

        if(data.contains("image_url")){
            tmp.imageURL = data["image_url"];
        }

        if(data.contains("book_id")){
            tmpString = data["book_id"];
            if(!tmpString.empty())
                tmp.id = std::stoi(tmpString);
        }

        hash.insertKey(tmp.title, tmp);

        }
*/
    while(!fileEnd){
        try{
            data.clear();
            file >> data;
        }
        catch(json::parse_error& excp){
            //std::cout << "EXCEPTION";
            fileEnd = true;
            break;
        }

        tmpVec.clear();
        tmpIntVec.clear();
        tmpString.clear();


        tmp.isbn = data["isbn"];
        tmp.title = data["title"];
        tmpString = data["average_rating"];
        if(!tmpString.empty())
            tmp.avgRating = std::stod(tmpString);

        for(const auto& element : data["similar_books"]){
            tmpString = element;
            if(!tmpString.empty())
                tmp.similarBooks.push_back(std::stoi(tmpString));
            }

        tmp.description = data["description"];

        tmp.url = data["link"];

        for(auto element : data["authors"]){
            tmpString = element["author_id"];
            if(!tmpString.empty())
                tmp.authors.push_back(tmpString);
            }


            tmp.publisher = data["publisher"];


            tmpString = data["num_pages"];
            if(!tmpString.empty())
                tmp.numPages = std::stoi(tmpString);



            tmpString = data["publication_year"];
            if(!tmpString.empty())
                tmp.publicationYear = std::stoi(tmpString);

            tmp.imageURL = data["image_url"];


            tmpString = data["book_id"];
            if(!tmpString.empty())
                tmp.id = std::stoi(tmpString);

        hash.insertKey(tmp.title, tmp);

    }


    std::cout << "DONE";
    }



