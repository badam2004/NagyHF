#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <iostream>
#include "Content.h"

class Article : public Content {
private:
    std::string title;      //Cím
    std::string content;    //Mit tartalmaz
    std::string author;     //Szerző
public:
    //Konstruktor
    Article(std::string title_, std::string content_, std::string author_): title(title_), content(content_), author(author_) {}

    //Getterek
    std::string getTitle() const { return title; }
    std::string getContent() const { return content; }
    std::string getAuthor() const { return author; }
    std::string getType() const { return "Cikk"; }

    //Setterek
    void setTitle(const std::string& title_) { title = title_; }
    void setContent(const std::string& content_) { content = content_; }
    void setAuthor(const std::string& author_) { author = author_; }

    //Kiiratás
    void display() const override {
        std::cout << "Cikk: " << title << "| Szerzo: " << author << "\n" << "Cikk Szovege: " << "\t" << content << "\n" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Article& article){
        os << "Cikk: " << article.title << "\n" << "Szovege: " << article.content;
    return os;
    };
};

#endif // ARTICLE_H
