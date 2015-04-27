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
    /** The person to whom this relationship belongs */
    Person* from_ = nullptr;
    /** The person that this relationship is with */
    Person* to_ = nullptr;
    /** The type of the relationship */
    RelationshipType* type_ = nullptr;
public:
    // From, to, and type are required to construct the relationship
    Relationship(Person* from, Person* to, RelationshipType* type) : from_(from), to_(to), type_(type) {}

    /**
     * @return the person the relationship is with
     */
    Person* getFrom();

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
