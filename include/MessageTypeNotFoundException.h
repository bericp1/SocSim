#ifndef SOCSIM_MESSAGETYPENOTFOUNDEXCEPTION_H
#define SOCSIM_MESSAGETYPENOTFOUNDEXCEPTION_H

#include <exception>

/**
 * Thrown when a relationship type is being added but it contains a probability of message transfer for a message type
 * that does not exist in the society
 */
class MessageTypeNotFoundException : public std::exception {};

#endif //SOCSIM_MESSAGETYPENOTFOUNDEXCEPTION_H
