#ifndef SOCSIM_DISPATCHER_H
#define SOCSIM_DISPATCHER_H


#include <map>
#include <string>
#include "MessageType.h"

class Dispatcher {
private:
    typedef std::map<std::string, MessageType*> MessageTypes;

    typedef MessageTypes::iterator MessageTypesIterator;

    MessageTypes message_types_;
public:
    MessageType* addMessageType(MessageType* type);
    MessageType* addMessageType(const std::string& name, float default_probability, unsigned int max);
    MessageType* addMessageType(const std::string& name, float default_probability);
    MessageType* addMessageType(const std::string& name, unsigned int max);
    MessageType* addMessageType(const std::string& name);
    MessageType* findMessageType(const std::string& name);
    std::string serialize();
};


#endif //SOCSIM_DISPATCHER_H
