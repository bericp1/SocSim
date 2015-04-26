#include <DuplicateMessageTypeException.h>
#include "Dispatcher.h"

Dispatcher::~Dispatcher() {
    MessageTypesIterator it;
    for(it = this->message_types_.begin(); it != this->message_types_.end(); ++it) {
        delete it->second;
    }
    this->message_types_.clear();
}
MessageType* Dispatcher::addMessageType(MessageType* type) {
    if(this->message_types_.count(type->getName()) == 1) {
        delete type;
        throw new DuplicateMessageTypeException;
    }

    this->message_types_[type->getName()] = type;

    return type;
}
MessageType* Dispatcher::addMessageType(const std::string& name, float default_probability, unsigned int max) {
    return this->addMessageType(new MessageType(name, default_probability, max));
}
MessageType* Dispatcher::addMessageType(const std::string& name, float default_probability) {
    return this->addMessageType(new MessageType(name, default_probability));
}
MessageType* Dispatcher::addMessageType(const std::string& name, unsigned int max) {
    return this->addMessageType(new MessageType(name, max));
}
MessageType* Dispatcher::addMessageType(const std::string& name) {
    return this->addMessageType(new MessageType(name));
}
MessageType* Dispatcher::findMessageType(const std::string& name) {
    MessageTypesIterator it = this->message_types_.find(name);
    if(it == this->message_types_.end())
        return nullptr;
    else return it->second;
}
std::string Dispatcher::serialize(std::string line_prefix) {
    std::string output = "";

    if(this->message_types_.size() != 0)
        for(MessageTypesIterator it = this->message_types_.begin(); it != this->message_types_.end(); ++it)
            output += (line_prefix + it->second->getName() + "\n");
    else
        output += (line_prefix + "(none)\n");

    return output;
}
std::string Dispatcher::serialize() {
    return this->serialize("");
}