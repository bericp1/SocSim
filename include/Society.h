#ifndef PROJECT_SOCIETY_H
#define PROJECT_SOCIETY_H

#include <vector>
#include <map>
#include "MessageType.h"
#include "RelationshipType.h"
#include "Person.h"
#include "Relationship.h"
#include "Dispatcher.h"

/**
 * Represents a society of people
 * This is the actual graph
 */
class Society {
private:
    /**
     * A container for all possible relationship types. A map is used for quick searching
     * Key: name of relationship type
     * Value: relationship type
     */
    typedef std::map<std::string, RelationshipType*> RelationshipTypes;
    /**
     * A container for all people in the society. A map is used for quick searching
     * Key: the name of the person
     * Value: the person
     */
    typedef std::map<std::string, Person*> People;

    // Shortcuts to the two iterator types for the above containers
    typedef RelationshipTypes::iterator RelationshipTypesIter;
    typedef People::iterator PeopleIter;

    // Instances of the actual containers for relationship types and people
    RelationshipTypes relationship_types_;
    People people_;

    // The dispatcher associated with this society; shares lifecycle with Society
    Dispatcher* dispatcher_ = nullptr;
public:
    /**
     * Creates a new dispatcher on construction
     */
    Society();
    /**
     * Frees memory used for dispatcher, relationship types, and people
     */
    ~Society();

    /**
     * Find a relationship type by name
     * @param name the name of the relationship type to search for
     * @return the relationship type if found; null otherwise
     */
    RelationshipType* findRelationshipType(const std::string& name);
    /**
     * Register a new relationship type
     * @param name the name of the relationship type to add
     * @return the new relationship type
     */
    RelationshipType* addRelationshipType(const std::string& name);

    /**
     * Find a person by name
     * @param name the name of the person to find
     * @return the person if found; null otherwise
     */
    Person* findPerson(const std::string& name);
    /**
     * Add a person to the society
     * @param name the person's name
     * @param occupation the person's occupation
     * @return the new person
     */
    Person* addPerson(const std::string& name, const std::string& occupation);

    /**
     * Establish a relationship between two people in the society
     * @param from the person that relationship belongs to or starts at
     * @param to the person the relationship is with
     * @param type the type of the relationship
     * @return the new relationship
     */
    Relationship* relate(Person* from, Person* to, RelationshipType* type);
    /**
     * Alias for Society::relate that finds the people by name first
     */
    Relationship* relate(const std::string& from, const std::string& to, RelationshipType* type);
    /**
     * Alias for Society::relate  that find both the people and the type by name first
     */
    Relationship* relate(const std::string& from, const std::string& to, const std::string& type);

    /**
     * @return the active dispatcher for the society
     */
    Dispatcher* getDispatcher();

    /**
     * Get a string representation of the society including all registered relationship types, people, and the state of
     * the dispatcher
     * @return the string representation
     */
    std::string serialize();
};


#endif //PROJECT_SOCIETY_H