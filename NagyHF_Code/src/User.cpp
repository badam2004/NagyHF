#include "User.h"
#include <iostream>

using std::string;
using std::cerr;
using std::endl;
using std::cout;

// Konstruktor
User::User(string username_, string password_, int role_) {
    username = username_;
    password = password_;
    if (role_ >= READER && role_ <= ADMIN) {
        role = static_cast<Role>(role_);
    } else {
        cerr << "Hiba: �rv�nytelen szerepk�d (" << role_ << "), alap�rtelmezettk�nt READER lesz." << endl;
        role = READER;
    }
}

// A user szerep�nek be�ll�t�sa
void User::setRole(const int role_) {
    if (role_ >= READER && role_ <= ADMIN)
        role = static_cast<Role>(role_);
    else
        cerr << "Hiba: �rv�nytelen szerepk�d (" << role_ << ")" << endl;
}

// Kiirat�s << N�v << milyen szerepk�re van
void User::showDashboard() const {
    string user_role;
    switch (role) {
        case READER:
            user_role = "reader";
            break;
        case AUTHOR:
            user_role = "author";
            break;
        case ADMIN:
            user_role = "admin";
            break;
        default:
            user_role = "Not defined";
            break;
    }
    cout << username << " ir�ny�t�pultja (" << user_role << ")\n";
}

//Kiirat�shoz egy user-hez
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Nev: " << user.username <<  "| Jelszo:" << user.password <<" | Szerepkor: " << user.role;
    return os;
}
