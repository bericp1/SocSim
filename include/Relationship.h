#ifndef SOCSIM_RELATIONSHIP_H
#define SOCSIM_RELATIONSHIP_H

#include "RelationshipType.h"

// Forward decl
class Person;

/**
 * Represents a relationship (typed and directed) between two people
 * This is the edge in the graph (directed)
 */
class Relationship {
private:
    /** The person that this relationship is with */
    Person* to_ = nullptr;
    /** The type of the relationship */
    RelationshipType* type_ = nullptr;
public:
    // Both to and type are rquired to construct the relationship
    Relationship(Person* to, RelationshipType* type) : to_(to), type_(type) {}

    /**
     * @return the person the relationship is with
     */
    Person* getTo();
    /**
     * @return the type of the relationship
     */
    RelationshipType* getType();
};


#endif //SOCSIM_RELATIONSHIP_H
