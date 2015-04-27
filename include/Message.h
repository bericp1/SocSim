#ifndef SOCSIM_MESSAGE_H
#define SOCSIM_MESSAGE_H

#include <string>
#include "Relationship.h"

/**
 * Represents a message that can be sent through the society graph
 */
class Message {
private:
    /**
     * A map that tracks what relationships this specific message has been transferred across
     * Key: relationship
     * Value: true for successful transfer; false otherwise
     */
    typedef std::map<Relationship*, bool> Considered;
    typedef Considered::reverse_iterator ConsideredIter;

    /** The contents of the message */
    std::string contents_ = "";
    /** The type of the message */
    MessageType* type_ = nullptr;
    /** The map for tracking of traversed relationships */
    Considered considered_;
public:
    /**
     * Generates a random float on [0, 1]
     * Pre-conditions:
     *  * srand must have been previously called to seed the generator
     * @return random float on [0, 1]
     */
    static float rand();

    // Default constructor requires contents and type
    Message(std::string contents, MessageType* type) : contents_(contents), type_(type) {}
    virtual ~Message();

    /**
     * @return the message contents
     */
    const std::string& getContents();
    /**
     * Set the message contents
     * @param contents the new contents
     */
    void setContents(std::string contents);

    /**
     * @return the type of the message
     */
    MessageType* getType();
    /**
     * Change the message type
     * Pre-conditions:
     *  * The provided type is one that exists and is registered in the society
     * @param type the new type
     */
    void setType(MessageType* type);

    /**
     * Consider a relationship by using a random number generator and the probability that this type of message will
     * transfer over the specified relationship (which is based off of the relationship type). If transfer was
     * successful, relationship is stored in this->considered_ with a value of true; otherwise it's stored with a value
     * of false. Either way it is stored in the map in order to know what relationships have already been tested.
     *
     * Also note that if the message is successfully transferred across the relationship that if there's a relationship
     * going in the opposite direction of the specified relationship between the same two people, it will be added to
     * the this->considered_ map with a value of false (failed transfer) since it doesn't make sense for someone to
     * receive a message and then send it back to the person they received it from.
     *
     * Pre-conditions:
     *  * The specified relationship is one that exists in between two people that exist in the society
     *  * The specified relationship has a type that is registered in the existing society
     *  * There are no relationships between two people in the same direction with different types
     * Post-condition:
     *  * Relationship and its result from the probability calculation are stored in this->considered_
     *
     * @param relationship the relationship to attempt to cross/transfer across
     * @return true if successful transfer; false otherwise
     */
    bool consider(Relationship* relationship);

    /**
     * Check to see if a relationship has been considered/tested
     *
     * Pre-conditions:
     *  * The specified relationship is one that exists in between two people that exist in the society
     *  * The specified relationship has a type that is registered in the existing society
     *
     * @param relationship the relationship to check against
     * @return whether or not their exists an entry in the this->considered_ map for this relationship
     */
    bool wasConsidered(Relationship* relationship);

    /**
     * Get a string representation of this message
     * @param line_prefix prepended to every line in the output
     * @return the string representation
     */
    std::string serialize(std::string line_prefix);
    /**
     * An alias of Message::serialize with a blank line_prefix
     */
    std::string serialize();
};


#endif //SOCSIM_MESSAGE_H
