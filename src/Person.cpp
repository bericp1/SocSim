#include <DuplicateRelationshipException.h>
#include "Person.h"

Person::~Person() {
    RelationshipsIter it;
    for(it = this->relationships_.begin(); it != this->relationships_.end(); ++it) {
        delete it->second;
    }
    this->relationships_.clear();
}
const std::string& Person::getName() {
    return this->name_;
}
void Person::setOccupation(const std::string& occupation) {
    this->occupation_ = occupation;
}
const std::string& Person::getOccupation() {
    return this->occupation_;
}
bool Person::isRelatedTo(Person* person) {
    return (this->relationships_.count(person) == 1);
}
Relationship* Person::relateTo(Person* person, RelationshipType* type) {
    if(this->isRelatedTo(person)) {
        throw new DuplicateRelationshipException;
    }

    Relationship* relationship = new Relationship(person, type);

    this->relationships_[person] = relationship;

    return relationship;
}
std::string Person::serialize() {
    return this->serialize("");
}
std::string Person::serialize(std::string line_prefix) {
    std::string output = (line_prefix + this->getName() + " - " + this->getOccupation() + "\n");

    RelationshipsIter it;

    for(it = this->relationships_.begin(); it != this->relationships_.end(); ++it) {
        output += (line_prefix + "\tis " + it->second->getType()->getName() + " " + it->second->getTo()->getName() + "\n");
    }

    return output;
}
