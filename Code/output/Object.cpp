#include "Object.h"

class Object {
public:
    string name;
    string mail;
    string password;
    string note;

    Object(string name, string mail, string password, string note) {
        this->name = name;
        this->mail = mail;
        this->password = password;
        this->note = note;
    }
};
