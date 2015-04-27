#include <cstdlib>
#include <algorithm>
#include "Message.h"
#include "Person.h"

Message::~Message() {
    this->considered_.clear();
}

float Message::rand() {
    return static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
}

const std::string& Message::getContents() {
    return this->contents_;
}
void Message::setContents(std::string contents) {
    this->contents_ = contents;
}

MessageType* Message::getType() {
    return this->type_;
}
void Message::setType(MessageType* type) {
    this->type_ = type;
}

bool Message::consider(Relationship* relationship) {
    float probability = relationship->getType()->getProbability(this->getType());
    bool result = (Message::rand() < probability);
    this->considered_[relationship] = result;
    Relationship* possible_back_relationship = relationship->getTo()->getRelationship(relationship->getFrom());
    if(possible_back_relationship != nullptr)
        this->considered_[possible_back_relationship] = false;
    return result;
}
bool Message::wasConsidered(Relationship* relationship) {
    return (this->considered_.count(relationship) > 0);
}

std::string Message::serialize(std::string line_prefix) {
    std::string output = (line_prefix + "Message:\n");

    output += (line_prefix + "\tType:\n" + line_prefix + "\t\t" + this->getType()->getName() + "\n");

    output += (line_prefix + "\tContents:\n" + line_prefix + "\t\t" + this->getContents() + "\n");

    output += (line_prefix + "\tTransfers:\n");

    unsigned int succesfuls = 0;
    for(ConsideredIter iter = this->considered_.rbegin(); iter != this->considered_.rend(); ++iter) {
        if(iter->second) {
            output += (line_prefix + "\t\t" + iter->first->getFrom()->getName() + " -> " + iter->first->getTo()->getName() + "\n");
            succesfuls++;
        }
    }

    if(succesfuls == 0)
        output += (line_prefix + "\t\t(none)\n");

    return output;
}
std::string Message::serialize() {
    return this->serialize("");
}
