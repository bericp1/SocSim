#ifndef SOCSIM_DUPLICATEMESSAGETYPEEXCEPTION_H
#define SOCSIM_DUPLICATEMESSAGETYPEEXCEPTION_H

#include <exception>

/**
 * Thrown when a message type is registered on a dispatcher that already has a message type with that name
 */
class DuplicateMessageTypeException : public std::exception {};

#endif //SOCSIM_DUPLICATEMESSAGETYPEEXCEPTION_H
