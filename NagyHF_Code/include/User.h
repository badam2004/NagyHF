#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
public:
    enum Role {
        READER = 0,
        AUTHOR = 1,
        ADMIN = 2
    };

private:
    std::string username;
    std::string password;
    Role role;

public:
    //Konstruktorok
    User(std::string username_, std::string password_, int role_);
    User(const User& other): username(other.username), password(other.password), role(other.role){}

    // Getterek
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    Role getRole() const { return role; }

    // Setterek
    void setUsername(const std::string& username_) { username = username_; }
    void setPassword(const std::string& password_) { password = password_; }
    void setRole(int role_);

    // Dashboard megjelenítése
    void showDashboard() const;

    // Jogosultság ellenőrzők
    bool canRead() const { return role >= READER; }
    bool canPost() const { return role >= AUTHOR; }
    bool isAdmin() const { return role == ADMIN;  }

    //Kiíratáshoz
    friend std::ostream& operator<<(std::ostream& os, const User& user);

};

#endif // USER_H

