#ifndef SOCSIM_DRIVER_H
#define SOCSIM_DRIVER_H


#include "Society.h"

class Driver {
private:
    Society* society_ = nullptr;
    bool running_ = false;
public:
    static std::string getStringFromUser(std::string prompt);
    static std::string getStringFromUser();
    static int getIntFromUser(std::string prompt);
    static int getIntFromUser();

    virtual ~Driver();

    void menu();
    void run(int command);
    void start();
};


#endif //SOCSIM_DRIVER_H
