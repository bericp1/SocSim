#ifndef SOCSIM_DISPATCHERREPORT_H
#define SOCSIM_DISPATCHERREPORT_H


#include <vector>
#include "Message.h"

/**
 * Represents and stores the results from a message being sent through the society graph
 */
class DispatcherReport {
public:
    /**
     * Represents a path that the message took
     */
    typedef std::vector<Person*> Path;
    /**
     * A collection of paths taken
     */
    typedef std::vector<Path> Paths;
    // Iterators for the above types
    typedef Path::iterator PathIter;
    typedef Paths::iterator PathsIter;
private:
    /** The message this report is for */
    Message* message_ = nullptr;
    /** The paths the message took */
    Paths paths_;
public:
    // Default constructor requires message
    DispatcherReport(Message* message) : message_(message) {}
    virtual ~DispatcherReport();

    /**
     * Add a path to the collection of paths
     * Pre-conditions:
     *  * path is longer than one person
     * Post-conditions:
     *  * Path is added to this->paths_
     */
    void recordPath(Path path);

    /**
     * Get a string representation of the report
     * @param line_prefix prepended to each line of output
     * @return the string representation
     */
    std::string serialize(std::string line_prefix);
    /**
     * An alias of DispatcherReport::serialize with a blank line_prefix
     */
    std::string serialize();
};


#endif //SOCSIM_DISPATCHERREPORT_H
