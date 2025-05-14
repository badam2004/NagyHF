#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <iostream>
#include "Content.h"
#include "Article.h"

class Comment : public Content {
    std::string text;            // maga a komment
    std::string username;        // felhaszn�l�n�v
    std::string articleTitle;    // az �js�g c�me
public:
    //Konstruktor
    Comment(std::string comment_, std::string username_, std::string articleTitle_);

    //Getterek
    std::string getText() const { return text; }
    std::string getUsername() const { return username; }
    std::string getArticleTitle() const { return articleTitle; }
    std::string getType() const override { return "Komment"; }

    //Setterek
    void setText(const std::string& text_) { text = text_; }
    void setUsername(const std::string& username_) { username = username_; }
    void setArticleTitle(const std::string& articleTitle_) { articleTitle = articleTitle_; }

    //Kiirart�s << mindent kiirat
    void display() const;

    //Kiirat�s << Ki << Mit
    friend std::ostream& operator<<(std::ostream& os, const Comment& comment_);
};

#endif // COMMENT_H
