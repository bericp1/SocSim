#include "MessageType.h"

const std::string& MessageType::getName() {
    return this->name_;
}
float MessageType::getDefaultProbability() {
    return this->default_probability_;
}
unsigned int MessageType::getMax() {
    return this->max_;
}
