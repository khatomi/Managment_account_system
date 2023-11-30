#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object 
{
public:
    Object(const std::string& name, const std::string& mail, const std::string& password, const std::string& note);
    std::string getName() const;
    std::string getMail() const;
    std::string getPassword() const;
    std::string getNote() const;
    void setMail(const std::string& mail);
    void setPassword(const std::string& password);
    void setNote(const std::string& note);
private:
    std::string name_;
    std::string mail_;
    std::string password_;
    std::string note_;
};

#endif // OBJECT_H