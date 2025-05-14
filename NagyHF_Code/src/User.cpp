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
        cerr << "Hiba: Érvénytelen szerepkód (" << role_ << "), alapértelmezettként READER lesz." << endl;
        role = READER;
    }
}

// A user szerepének beállítása
void User::setRole(const int role_) {
    if (role_ >= READER && role_ <= ADMIN)
        role = static_cast<Role>(role_);
    else
        cerr << "Hiba: érvénytelen szerepkód (" << role_ << ")" << endl;
}

// Kiiratás << Név << milyen szerepköre van
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
    cout << username << " irányítópultja (" << user_role << ")\n";
}

//Kiiratáshoz egy user-hez
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Nev: " << user.username <<  "| Jelszo:" << user.password <<" | Szerepkor: " << user.role;
    return os;
}
