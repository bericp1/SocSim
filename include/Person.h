#ifndef SOCSIM_PERSON_H
#define SOCSIM_PERSON_H


#include <map>
#include <string>
#include "Relationship.h"
#include "RelationshipType.h"

class Person {
private:
    typedef std::map<Person*, Relationship*> Relationships;

    typedef std::map<Person*, Relationship*>::iterator RelationshipsIter;

    std::string name_;
    std::string occupation_;
    Relationships relationships_;

public:
    Person(const std::string& name) : name_(name), occupation_("") {}
    Person(const std::string& name, const std::string& occupation) : name_(name), occupation_(occupation) {}
    virtual ~Person();

    const std::string& getName();

    void setOccupation(const std::string& occupation);
    const std::string& getOccupation();

    bool isRelatedTo(Person* person);

    Relationship* relateTo(Person* person, RelationshipType* type);

    std::string serialize(std::string line_prefix);
    std::string serialize();
};


#endif //SOCSIM_PERSON_H
