#include "Relationship.h"

Person* Relationship::getTo() {
    return this->to_;
}
Person* Relationship::getFrom() {
    return this->from_;
}
RelationshipType* Relationship::getType() {
    return this->type_;
}
