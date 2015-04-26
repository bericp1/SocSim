#include "Relationship.h"

Person* Relationship::getTo() {
    return this->to_;
}
RelationshipType* Relationship::getType() {
    return this->type_;
}
