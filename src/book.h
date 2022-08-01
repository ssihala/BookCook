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
        publisher="";
        numPages=-1;
        publicationYear=-1;
    }
    int id;
    std::string title;
    std::string isbn;
    double avgRating;
    std::vector<int> similarBooks;
    std::vector<std::string> genres;
    std::string publisher;
    int numPages;
    int publicationYear;
};
