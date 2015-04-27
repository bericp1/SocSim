#ifndef SOCSIM_PERSON_H
#define SOCSIM_PERSON_H


#include <map>
#include <string>
#include "Relationship.h"
#include "RelationshipType.h"

/**
 * Represents a person in the society
 * This is the node in the graph
 */
class Person {
private:
    /**
     * A container type for relationships. A map is used for quick searching
     * Key: person
     * Value: relationship
     */
    typedef std::map<Person*, Relationship*> Relationships;
    /**
     * A shortcut to the container's iterator
     */
    typedef std::map<Person*, Relationship*>::iterator RelationshipsIter;

    /** The name of this person */
    std::string name_;
    /** This person's occupation */
    std::string occupation_;
    /** All of this person's relationships to other people */
    Relationships relationships_;

public:
    // A few constructors for setting default data. Only a name is required upon construction
    Person(const std::string& name) : name_(name), occupation_("") {}
    Person(const std::string& name, const std::string& occupation) : name_(name), occupation_(occupation) {}
    virtual ~Person();

    /**
     * @return the name of the person
     */
    const std::string& getName();

    /**
     * Change the person's occupation.
     * @param occupation the new occupation
     */
    void setOccupation(const std::string& occupation);
    /**
     * @return the occupation of the user
     */
    const std::string& getOccupation();

    /**
     * See if a relationship exists between this person and another specified person
     * @param person the person to look for in the relationships
     * @return true if the person has a relationship to the specified person; false otherwise
     */
    bool isRelatedTo(Person* person);

    /**
     * Establish a relationship between this person and a specified person
     * @param person the person that the relationship should be established with
     * @param type the type of the relationship
     * @return the new relationship
     */
    Relationship* relateTo(Person* person, RelationshipType* type);

    /**
     * Get a string representation of the person including their name, occupation, and relationships
     * @param line_prefix prepended to each line of the output
     * @return the string representation
     */
    std::string serialize(std::string line_prefix);
    /**
     * An alias to Person::serialize with a blank line_prefix
     */
    std::string serialize();
};


#endif //SOCSIM_PERSON_H
