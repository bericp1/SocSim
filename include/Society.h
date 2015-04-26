#ifndef PROJECT_SOCIETY_H
#define PROJECT_SOCIETY_H

#include <vector>
#include <map>
#include "MessageType.h"
#include "RelationshipType.h"
#include "Person.h"
#include "Relationship.h"
#include "Dispatcher.h"

class Society {
private:
    typedef std::map<std::string, RelationshipType*> RelationshipTypes;
    typedef std::map<std::string, Person*> People;

    typedef RelationshipTypes::iterator RelationshipTypesIter;
    typedef People::iterator PeopleIter;

    RelationshipTypes relationship_types_;
    People people_;

    Dispatcher* dispatcher_ = nullptr;
public:
    Society();
    ~Society();

    RelationshipType* findRelationshipType(const std::string& name);
    RelationshipType* addRelationshipType(const std::string& name);

    Person* findPerson(const std::string& name);
    Person* addPerson(const std::string& name, const std::string& occupation);

    Relationship* relate(Person* from, Person* to, RelationshipType* type);
    Relationship* relate(const std::string& from, const std::string& to, RelationshipType* type);
    Relationship* relate(const std::string& from, const std::string& to, const std::string& type);

    Dispatcher* getDispatcher();

    std::string serialize();
};


#endif //PROJECT_SOCIETY_H