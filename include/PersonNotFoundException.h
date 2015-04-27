#ifndef SOCSIM_PERSONNOTFOUNDEXCEPTION_H
#define SOCSIM_PERSONNOTFOUNDEXCEPTION_H

#include <exception>

/**
 * Thrown when attempting to establish a relationship between one or more people who don't currently exist in the
 * society.
 */
class PersonNotFoundException : public std::exception {};

#endif //SOCSIM_PERSONNOTFOUNDEXCEPTION_H
