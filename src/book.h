//
// Created by sihala on 7/20/22.
//

#pragma once
#include <vector>
#include <string>

struct Book{
    Book() {
        id=-1;
        title="";
        isbn="";
        avgRating=-1;
        description="";
        url="";
        publisher="";
        numPages=-1;
        publicationYear=-1;
        imageURL="";
    }
    int id;
    std::string title;
    std::string isbn;
    double avgRating;
    std::vector<int> similarBooks;
    std::string description;
    std::string url;
    std::vector<std::string> authors;
    std::string publisher;
    int numPages;
    int publicationYear;
    std::string imageURL;
};
