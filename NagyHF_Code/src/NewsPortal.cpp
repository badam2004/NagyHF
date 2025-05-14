#include "NewsPortal.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istringstream;

//Article hozzáadása
void NewsPortal::addArticle(const string& title_, const string& content_, const string& author_) {
    Article temp(title_, content_, author_);
    articles.push_back(temp);
}

//Comment hozzáadása
void NewsPortal::addComment(const string& comment_, const string& username_, const string& articleTitle_) {
    bool found = false;

    for (const auto& article : articles)
        if (article.getTitle() == articleTitle_) {
            found = true;
            break;
        }

    if (!found) {
        cerr << "Hiba: Nem található olyan cikk, amelynek címe: \"" << articleTitle_ << "\"\n";
        return;
    }

    Comment temp(comment_, username_, articleTitle_);
    comments.push_back(temp);
}

//Újságok keresése Comment szerint
void NewsPortal::listCommentsForArticle(const string& articleTitle_) const {
    bool found = false;
    for (const auto& temp : comments) {
        if (temp.getArticleTitle() == articleTitle_) {
            cout << temp.getText() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Nem találtam kommentet az újsághoz!" << endl;
    }
}

//Író szerinti keresés az újságcikkekben
vector<Article> NewsPortal::searchByAuthor(const string& author_) {
    vector<Article> temp;
    for (const auto& i : articles)
        if (i.getAuthor() == author_)
            temp.push_back(i);
    return temp;
}

//Cím szerinti keresés az újságcikkekben
vector<Article> NewsPortal::searchByTitle(const string& title_) {
    vector<Article> temp;
    for (const auto& i : articles)
        if (i.getTitle() == title_)
            temp.push_back(i);
    return temp;
}

//név szerinti keresés, hogy a többi user tulajdonságot is tudjam használni
User* NewsPortal::getUserByName(const string& username) {
    for (auto& user : users) {
        if (user.getUsername() == username)
            return &user;
    }
    return nullptr;
}

//Belépéshez
bool NewsPortal::authenticateUser(const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    Fileból olvasnak ki
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//A Felhasználókhoz
void NewsPortal::readUsersFromFile(const string& filename) {
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Nem lehet a fájlt megnyitni!" << endl;
        exit(-1);
    }

    while (std::getline(file, line)) {

        string username, password;
        int role;

        istringstream iss(line);
        if (iss >> username >> password >> role) {
            User temp(username, password, role);
            users.push_back(temp);
        }
    }
}

//Az Újságokhoz
void NewsPortal::readArticlesFromFile(const string& filename){
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Nem lehet a fájlt megnyitni!" << endl;
        exit(-1);
    }

    while (std::getline(file, line)) {

        string title, content, author;

        istringstream iss(line);
        if (iss >> title >> content >> author) {
            Article temp(title, content, author);
            articles.push_back(temp);
        }
    }
}

//A Kommentekhez
void NewsPortal::readCommentsFromFile(const string& filename){
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Nem lehet a fájlt megnyitni!" << endl;
        exit(-1);
    }

    while (std::getline(file, line)) {

        string text, username, title;

        istringstream iss(line);
        if (iss >> text >> username >> title) {
            Comment temp(text, username, title);
            comments.push_back(temp);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    Listázásokhoz
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//A Felhasználókhoz
void NewsPortal::listUsers() const {
    for (int i = 0; i < users.size(); i ++) {
        cout << users[i] << endl;
    }
}

//Az Újságokhoz
void NewsPortal::listArticles() const {
    for (const auto& article : articles) {
        article.display();
    }
}
