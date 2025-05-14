#include "Comment.h"

using std::string;
using std::ostream;
using std::move;
using std::cout;

// Konstruktor
Comment::Comment(string comment_, string username_, string articleTitle_): text(move(comment_)), username(move(username_)), articleTitle(move(articleTitle_)) {}
// Kiiratáshoz
void Comment::display() const {
    cout << *this;
}

// << operátor túlterhelése kiiratáshoz
ostream& operator<<(ostream& os, const Comment& comment_) {
    os << "Komment (#" << comment_.username << "): " << comment_.text << "\n";
    return os;
}
