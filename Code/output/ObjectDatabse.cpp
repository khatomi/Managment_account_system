#include "ObjectDatabase.h"

void ObjectDatabase::addObject(const Object& object) {
    objects_.push_back(object);
}

void ObjectDatabase::removeObject(int index) {
    objects_.erase(objects_.begin() + index);
}

int ObjectDatabase::getNumObjects() const {
    return objects_.size();
}

Object& ObjectDatabase::getObject(int index) {
    return objects_[index];
}

int ObjectDatabase::findObjectIndexByName(const std::string& name) const {
    for (int i = 0; i < objects_.size(); i++) {
        if (objects_[i].getName() == name) {
            return i;
        }
    }
    return -1;
}