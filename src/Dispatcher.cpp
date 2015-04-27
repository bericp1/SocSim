#include <queue>
#include "DuplicateMessageTypeException.h"
#include "Person.h"
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

DispatcherReport* Dispatcher::sendMessage(Person* origin, Message* message) {
    DispatcherReport* report = new DispatcherReport(message);

    // The following are all used for proper BFS of the graph
    std::queue<DispatcherReport::Path> to_process;
    DispatcherReport::Path cursor;
    DispatcherReport::Path next;
    Person::Relationships relationships;
    Person::RelationshipsIter rel_it;
    bool exhausted;

    cursor.push_back(origin);
    to_process.push(cursor);

    while(to_process.size() > 0) {
        cursor = to_process.front();
        to_process.pop();
        exhausted = true;

        if(message->getType()->getMax() == 0 || cursor.size()-1 < message->getType()->getMax()) {
            relationships = cursor.back()->getRelationships();
            for(rel_it = relationships.begin(); rel_it != relationships.end(); ++rel_it) {
                if(!message->wasConsidered(rel_it->second) && message->consider(rel_it->second)) {
                    exhausted = false;
                    next.clear();
                    next = cursor;
                    next.push_back(rel_it->second->getTo());
                    to_process.push(next);
                }
            }
        }

        if(exhausted && cursor.size() > 1)
            report->recordPath(cursor);
    }

    return report;
}

std::string Dispatcher::serialize(std::string line_prefix) {
    std::string output = "";

    if(this->message_types_.size() != 0)
        for(MessageTypesIterator it = this->message_types_.begin(); it != this->message_types_.end(); ++it) {
            output += (line_prefix + it->second->getName());
            if(it->second->getMax() > 0) {
                output += (" (can only be transferred " + std::to_string(it->second->getMax()) + " times)");
            }
            output += "\n";
        }
    else
        output += (line_prefix + "(none)\n");

    return output;
}
std::string Dispatcher::serialize() {
    return this->serialize("");
}
Dispatcher::Dispatcher(Society* society) {
    this->society_ = society;
}

