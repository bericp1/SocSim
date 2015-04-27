#ifndef SOCSIM_DISPATCHER_H
#define SOCSIM_DISPATCHER_H

// Forward decl
class Society;

#include <map>
#include <string>
#include "MessageType.h"
#include "DispatcherReport.h"

/**
 * Manages all messages that will be sent through a society.
 */
class Dispatcher {
private:
    /**
     * Represents a collection of message types. A map is used for quick searching
     * Key: message type name
     * Value: message type
     */
    typedef std::map<std::string, MessageType*> MessageTypes;
    /** Shortcut to the iterator type for MessageTypes */
    typedef MessageTypes::iterator MessageTypesIterator;

    /** The available message types */
    MessageTypes message_types_;

    /** A backreference to the society graph */
    Society* society_;
public:
    /** Society graph backreference is required */
    Dispatcher(Society* society);

    virtual ~Dispatcher();

    /**
     * Add an already constructed message type
     * @param type the message type
     * @return added message type
     */
    MessageType* addMessageType(MessageType* type);

    // Various aliases follow that construct message types using defaults for non-provided values
    MessageType* addMessageType(const std::string& name, float default_probability, unsigned int max);
    MessageType* addMessageType(const std::string& name, float default_probability);
    MessageType* addMessageType(const std::string& name, unsigned int max);
    MessageType* addMessageType(const std::string& name);

    /**
     * Find an existing message type by name
     * @param name the name of the message type
     * @return the message type if found; null otherwise
     */
    MessageType* findMessageType(const std::string& name);

    /**
     * Send a message through the graph
     * Post-conditions:
     *  * Memory management of returned report is responsibilty of caller
     * @param origin the person who the message starts at
     * @param message the message to send
     * @return the DispatcherReport with details about how the message traversed the society
     */
    DispatcherReport* sendMessage(Person* origin, Message* message);


    /**
     * Create a string representation of the dispatcher which only includes a list of registered message types
     * @param line_prefix prepended to each line of output
     */
    std::string serialize(std::string line_prefix);
    /**
     * Alias to Dispatcher::serialize with a blank line_prefix
     */
    std::string serialize();
};


#endif //SOCSIM_DISPATCHER_H
