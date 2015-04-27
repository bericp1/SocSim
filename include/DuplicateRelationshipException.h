#ifndef SOCSIM_DUPLICATERELATIONSHIPEXCEPTION_H
#define SOCSIM_DUPLICATERELATIONSHIPEXCEPTION_H

#include <exception>

/**
 * Thrown when an attempt is made to create a relationship between to people when a relationship already exists between
 * those two people. Note that relationships are directed to A->B will not collide with B->A
 */
class DuplicateRelationshipException : public std::exception {};

#endif //SOCSIM_DUPLICATERELATIONSHIPEXCEPTION_H
