#include "RelationshipType.h"

const std::string& RelationshipType::getName(){
    return this->name_;
}
void RelationshipType::setProbability(MessageType* type, float probability) {
    this->probabilities_[type] = probability;
}
float RelationshipType::getProbability(MessageType* type) {
    if(this->probabilities_.count(type) == 0)
        return 0;
    else
        return this->probabilities_[type];
}
