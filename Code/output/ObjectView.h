#ifndef OBJECT_VIEW_H
#define OBJECT_VIEW_H

#include <string>
#include "Object.h"

class ObjectView {
public:
    int showMenu();
    void getInput(std::string& name, std::string& mail, std::string& password, std::string& note);
    void getUpdateInput(std::string& mail, std::string& password, std::string& note);
    void getSearchInput(std::string& name);
    void showError(const std::string& message);
    void showObject(const Object& object);
};

#endif // OBJECT_VIEW_H