#ifndef SOCSIM_DRIVER_H
#define SOCSIM_DRIVER_H


#include "Society.h"

/**
 * Responsible for taking user input and showing output to the user regarding the society and messages and whatnot
 */
class Driver {
private:
    /** The society (graph) that will be manipulated */
    Society* society_ = nullptr;
    /** The state of the input/output loop */
    bool running_ = false;
public:
    /**
     * Gets a string as input from the user through std::cin
     * @param prompt output this before receiving input (no newline is added)
     * @return the user's input as a string
     */
    static std::string getStringFromUser(std::string prompt);
    /**
     * Alias to Driver::getStringFromUser with no prompt
     */
    static std::string getStringFromUser();
    /**
     * Gets an integer as input from the user through std::cin
     * @param prompt output this before receiving input (no newline is added)
     * @return the user's input as an int
     *
     * @uses Driver::getStringFromUser
     * @uses std::stoi
     */
    static int getIntFromUser(std::string prompt);
    /**
     * Alias for Driver::getIntFromUser with no prompt
     */
    static int getIntFromUser();

    /**
     * Cleans up society if non-null
     */
    virtual ~Driver();

    /**
     * Outputs the menu to STDOUT
     */
    void menu();

    /**
     * Runs the integer-specified command
     * @param command number that corresponds to a menu item
     */
    void run(int command);

    /**
     * Start looping, showing the menu and taking commands until the user selects "Quit"
     *
     * Post-conditions:
     *  * this->society_ may be null or non-null
     */
    void start();
};


#endif //SOCSIM_DRIVER_H
