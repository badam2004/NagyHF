#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <iostream>
#include "Content.h"

class Article : public Content {
private:
    std::string title;      //Cím
    std::string link;       //hozzá vezető link
    std::string author;     //Szerző
public:
    //Konstruktor
    Article(std::string title_, std::string link_, std::string author_): title(title_), link(link_), author(author_) {}

    //Getterek
    std::string getTitle() const { return title; }
    std::string getLink() const { return link; }
    std::string getAuthor() const { return author; }
    std::string getType() const { return "Cikk"; }

    //Setterek
    void setTitle(const std::string& title_) { title = title_; }
    void setlink(const std::string& link_) { link = link_; }
    void setAuthor(const std::string& author_) { author = author_; }

    //Kiiratás
    void display() const override {
        std::cout << "Cikk: " << title << "| Szerzo: " << author << "\n" << "Cikk Linkje: " << "\t" << link << "\n" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Article& article){
        os << "Cikk: " << article.title << "\n" << "Szovege: " << article.link;
    return os;
    };
};

#endif // ARTICLE_H
