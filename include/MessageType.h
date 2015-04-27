#ifndef SOCSIM_MESSAGETYPE_H
#define SOCSIM_MESSAGETYPE_H

#include <string>

/**
 * Represents a possible type that a message can have.
 */
class MessageType {
private:
    /** The name of the type; unique */
    std::string name_;
    /**
     * The default probability of message transfer that this type should be handled with if a relationship type doesn't
     * have a probability defined for this message type
     */
    float default_probability_ = 0.5;
    /**
     * The maximum number of times a message of this type can be transferred.
     * 0 = no limit
     */
    unsigned int max_ = 0;
public:
    // Various constructors for defining default data
    MessageType(const std::string& name) : name_(name) {}
    MessageType(const std::string& name, unsigned int max) : name_(name), max_(max) {}
    MessageType(const std::string& name, float default_probability) :
            name_(name), default_probability_(default_probability) {}
    MessageType(const std::string& name, float default_probability, unsigned int max) :
            name_(name), default_probability_(default_probability), max_(max) {}

    /**
     * @return the name of the type
     */
    const std::string& getName();

    /**
     * @return the default probability of message transfer for the type
     */
    float getDefaultProbability();

    /**
     * @return the max number of times a message of this type can be transferred
     */
    unsigned int getMax();
};

#endif //SOCSIM_MESSAGETYPE_H
