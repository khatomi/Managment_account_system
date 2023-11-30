#ifndef OBJECT_CONTROLLER_H
#define OBJECT_CONTROLLER_H

#include "Object.h"
#include "ObjectDatabase.h"
#include "ObjectView.h"

class ObjectController {public: OBJECT_H
public:
    ObjectController(ObjectDatabase& model, ObjectView& view);
    void addObject(const std::string& name, const std::string& mail, const std::string& password, const std::string& note);
    void removeObject(int index);
    void updateObject(int index, const std::string& mail, const std::string& password, const std::string& note);
    void displayAllObjects();
private:
    ObjectDatabase& model_;
    ObjectView& view_;
};

#endif // OBJECT_CONTROLLER_H