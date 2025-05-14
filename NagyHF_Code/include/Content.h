#ifndef CONTENT_H
#define CONTENT_H

#include <iostream>

//Interfész az article-höz és a Comment-hez
class Content {
public:
    virtual ~Content() = default;
    virtual void display() const = 0;
    virtual std::string getType() const = 0;
};

#endif // CONTENT_H
