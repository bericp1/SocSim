#ifndef SOCSIM_RELATIONSHIPTYPE_H
#define SOCSIM_RELATIONSHIPTYPE_H

#include <string>
#include <map>
#include "MessageType.h"

/**
 * Represents a type of relationship
 */
class RelationshipType {
private:
    /** The name for this type of relationship (e.g. "married to" or "is student to") */
    std::string name_;
    /**
     * A type for the map that contains probabilities of message transfer for specific message types. That is, each
     * type of relationship has different probabilities that a message will be transferred between the people that
     * the relationship relates depending on the type of message being transferred. For example, a rumor will have a
     * high probability of transfer between coworkers but a low probability between boss and employee.
     * Key: message type
     * Value: probability on the interval [0,1]
     */
    typedef std::map<MessageType*,float> Probabilities;
    /** The map of probabilities */
    Probabilities probabilities_;
public:
    // A name must be specified on construction
    RelationshipType(const std::string& name) : name_(name) {}

    /**
     * @return the name of the relationship type
     */
    const std::string& getName();

    /**
     * Set a probability for a specific message type
     * @param type the message type to set a probability for
     * @param probability the probability that a message of this type will be transferred.
     */
    void setProbability(MessageType* type, float probability);
    /**
     * Get a probability for a specific message type
     * @param type the type of message to get the probability of
     * @return the probability for the specified type; 0 if not found
     */
    float getProbability(MessageType* type);
};

#endif //SOCSIM_RELATIONSHIPTYPE_H
