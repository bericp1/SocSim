#ifndef SOCSIM_RELATIONSHIPTYPE_H
#define SOCSIM_RELATIONSHIPTYPE_H

#include <string>
#include <map>
#include "MessageType.h"

class RelationshipType {
private:
    std::string name_;
    std::map<MessageType*,float> probabilities_;
public:
    RelationshipType(const std::string& name) : name_(name) {}

    const std::string& getName();

    void setProbability(MessageType* type, float probability);
    float getProbability(MessageType* type);
};

#endif //SOCSIM_RELATIONSHIPTYPE_H
