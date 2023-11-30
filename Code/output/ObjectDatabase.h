#ifndef OBJECT_DATABASE_H
#define OBJECT_DATABASE_H

#include <vector>
#include "Object.h"

class ObjectDatabase {public: OBJECT_H
public:
    void addObject(const Object& object);
    void removeObject(int index);
    int getNumObjects() const;
    Object& getObject(int index);
    int findObjectIndexByName(const std::string& name) const;
private:
    std::vector<Object> objects_;
};

#endif // OBJECT_DATABASE_H