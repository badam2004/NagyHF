#ifndef NEWSPORTAL_H
#define NEWSPORTAL_H

#include <map>
#include <vector>
#include <string>
#include "Article.h"
#include "Comment.h"
#include "User.h"

class NewsPortal {
private:
    std::vector<Article> articles;
    std::vector<Comment> comments;
    std::vector<User> users;
public:
    //Hozz�ad�shoz-->> Ez csak a program �ppeni fut�siej�ig m�k�dik
    void addArticle(const std::string& title_, const std::string& content_, const std::string& author_);
    void addComment(const std::string& comment_, const std::string& username_, const std::string& articleTitle_);
    void addUser(const User& user_) { users.push_back(user_); }

    //Getterek
    std::vector<Article> getArticles(){ return(this->articles); }
    std::vector<Comment> getComments(){ return(this->comments); }
    std::vector<User> getuUsers(){ return(this->users); }

    //Keres�shez
    void listCommentsForArticle(const std::string& articleTitle_) const;

    //Konkr�t Tulajdons�g alapj�n val� keres�s      II      amit a class t�rol
    std::vector<Article> searchByAuthor(const std::string& author);
    std::vector<Article> searchByTitle(const std::string& title);

    //Bel�p�shez az elej�n
    bool authenticateUser(const std::string& username, const std::string& password);
    User* getUserByName(const std::string& username);

    //Fileb�l olvas ki
    void readCommentsFromFile(const std::string& filename);
    void readUsersFromFile(const std::string& filename);
    void readArticlesFromFile(const std::string& filename);

    //Fileba �r
    void writeAllCommentsToFile(const std::vector<Comment>& comments, const std::string& filename);

    //Lek�rdez�shez
    void listArticles() const;
    void listUsers() const;

};

#endif // NEWSPORTAL_H
