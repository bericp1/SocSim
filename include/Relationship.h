#ifndef SOCSIM_RELATIONSHIP_H
#define SOCSIM_RELATIONSHIP_H

#include "RelationshipType.h"

// Forward decl
class Person;

class Relationship {
private:
    Person* to_ = nullptr;
    RelationshipType* type_ = nullptr;
public:
    Relationship(Person* to, RelationshipType* type) : to_(to), type_(type) {}

    Person* getTo();
    RelationshipType* getType();
};


#endif //SOCSIM_RELATIONSHIP_H
