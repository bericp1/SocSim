#ifndef SOCSIM_MESSAGETYPE_H
#define SOCSIM_MESSAGETYPE_H

#include <string>

class MessageType {
private:
    std::string name_;
    float default_probability_ = 0.5;
    unsigned int max_ = 0;
public:
    MessageType(const std::string& name) : name_(name) {}
    MessageType(const std::string& name, unsigned int max) : name_(name), max_(max) {}
    MessageType(const std::string& name, float default_probability) :
            name_(name), default_probability_(default_probability) {}
    MessageType(const std::string& name, float default_probability, unsigned int max) :
            name_(name), default_probability_(default_probability), max_(max) {}

    const std::string& getName();
    float getDefaultProbability();
    unsigned int getMax();
};

#endif //SOCSIM_MESSAGETYPE_H
