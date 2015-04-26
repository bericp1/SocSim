#include <PersonNotFoundException.h>
#include <MessageTypeNotFoundException.h>
#include "Society.h"

Society::Society() {
    this->dispatcher_ = new Dispatcher;
}

Society::~Society() {
    RelationshipTypesIter rt_it;
    PeopleIter p_it;

    for(rt_it = this->relationship_types_.begin(); rt_it != this->relationship_types_.end(); ++rt_it) {
        delete rt_it->second;
    }
    this->relationship_types_.clear();

    for(p_it = this->people_.begin(); p_it != this->people_.end(); ++p_it) {
        delete p_it->second;
    }
    this->people_.clear();

    delete this->dispatcher_;
}
RelationshipType* Society::findRelationshipType(const std::string& name) {
    RelationshipTypesIter it = this->relationship_types_.find(name);
    if(it == this->relationship_types_.end())
        return nullptr;
    else return it->second;
}
RelationshipType* Society::addRelationshipType(const std::string& name) {
    RelationshipType* new_type = new RelationshipType(name);
    this->relationship_types_[name] = new_type;
    return new_type;
}
Person* Society::findPerson(const std::string& name) {
    PeopleIter it = this->people_.find(name);
    if(it == this->people_.end())
        return nullptr;
    else return it->second;
}
Person* Society::addPerson(const std::string& name, const std::string& occupation) {
    Person* person = this->findPerson(name);
    if(person != nullptr) {
        person->setOccupation(occupation);
    } else {
        person = new Person(name, occupation);
        this->people_[name] = person;
    }
    return person;
}
Relationship* Society::relate(Person* from, Person* to, RelationshipType* type) {
    return from->relateTo(to, type);
}
Relationship* Society::relate(const std::string& from, const std::string& to, RelationshipType* type) {
    Person* from_person = this->findPerson(from);
    if(from_person == nullptr) {
        throw new PersonNotFoundException;
    }

    Person* to_person = this->findPerson(to);
    if(to_person == nullptr) {
        throw new PersonNotFoundException;
    }

    return this->relate(from_person, to_person, type);
}
Relationship* Society::relate(const std::string& from, const std::string& to, const std::string& type_name) {
    RelationshipType* type = this->findRelationshipType(type_name);
    if(type == nullptr) {
        throw new MessageTypeNotFoundException;
    }

    return this->relate(from, to, type);
}
Dispatcher* Society::getDispatcher() {
    return this->dispatcher_;
}
std::string Society::serialize() {
    std::string output =
            "==================== State of Society ====================\n";

    PeopleIter p_it;
    RelationshipTypesIter rt_it;

    output += "# Relationship Types: \n";
    if(this->relationship_types_.size() == 0)
        output += "(none)\n";
    else
        for(rt_it = this->relationship_types_.begin(); rt_it != this->relationship_types_.end(); ++rt_it)
            output += (rt_it->second->getName() + "\n");

    output += "\n# People: \n";
    if(this->people_.size() == 0)
        output += "(none)\n";
    else
        for(p_it = this->people_.begin(); p_it != this->people_.end(); ++p_it)
            output += p_it->second->serialize();

    output += "\n# Message Types: \n";
    output += this->dispatcher_->serialize();

    output += "==========================================================\n\n";

    return output;
}
