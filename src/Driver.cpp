#include <iostream>
#include <Importer.h>
#include <DuplicateMessageTypeException.h>
#include <DuplicateRelationshipException.h>
#include <MessageTypeNotFoundException.h>
#include <PersonNotFoundException.h>
#include "Driver.h"

std::string Driver::getStringFromUser(std::string prompt) {
    std::string input = "";
    if(prompt != "") std::cout << prompt << std::flush;
    std::getline(std::cin, input);
    return input;
}
std::string Driver::getStringFromUser() {
    return Driver::getStringFromUser("");
}
int Driver::getIntFromUser(std::string prompt) {
    std::string input = Driver::getStringFromUser(prompt);
    return std::stoi(input);
}
int Driver::getIntFromUser() {
    return Driver::getIntFromUser("");
}

Driver::~Driver() {
    if(this->society_ != nullptr) delete this->society_;
}

void Driver::menu() {
    std::cout << "========================== Menu ==========================" << std::endl;
    std::cout << "\t1. Create new society" << std::endl;
    std::cout << "\t2. Show state of society" << std::endl;
    std::cout << "\t3. Import society data" << std::endl;
    std::cout << "\t4. Destroy society" << std::endl;
    std::cout << "\t0. Quit\n\n" << std::flush;
}
void Driver::run(int command) {
    switch(command) {
        case 1: {
            if(this->society_ != nullptr) {
                std::cout << "Destroying existing society... " << std::flush;
                delete this->society_;
                this->society_ = nullptr;
                std::cout << "Success!" << std::endl;
            }
            std::cout << "Creating new society... " << std::flush;
            this->society_ = new Society;
            std::cout << "Success!\n\n" << std::flush;
            break;
        }
        case 2: {
            if(this->society_ == nullptr) {
                std::cout << "No existing society.\n\n" << std::flush;
            } else {
                std::cout << this->society_->serialize() << std::endl;
            }
            break;
        }
        case 3: {
            try{
                if(this->society_ == nullptr) {
                    std::cout << "No existing society. Creating new society from data in \"./res\"... " << std::flush;
                    this->society_ = Importer::generate();
                    std::cout << "Success!\n\n" << std::flush;
                } else {
                    std::cout << "Importing data from \"./res/\"... " << std::flush;
                    Importer::importTo(this->society_);
                    std::cout << "Success!\n\n" << std::flush;
                }
            } catch(DuplicateMessageTypeException* e) {
                std::cerr << "Failed.\n"
                        "Import aborted due to collision. A message type defined in the imported data already exists in "
                        "the existing society.\n\n" << std::flush;
            } catch(DuplicateRelationshipException* e) {
                std::cerr << "Failed.\n"
                        "Import aborted due to collision. A relationship defined in the imported data already exists in "
                        "the existing society.\n\n" << std::flush;
            } catch(MessageTypeNotFoundException* e) {
                std::cerr << "Failed.\n"
                        "Import aborted due to bad data. A relationship type in the imported data depends on a message "
                        "type that doesn't exist in the existing society.\n\n" << std::flush;
            } catch(PersonNotFoundException* e) {
                std::cerr << "Failed.\n"
                        "Import aborted due to bad data. A relationship in the imported data depends on a person "
                        "that doesn't exist in the existing society.\n\n" << std::flush;
            }
            break;
        }
        case 4: {
            if(this->society_ == nullptr) {
                std::cout << "No existing society.\n\n" << std::flush;
            } else {
                std::cout << "Destroying existing society... " << std::flush;
                delete this->society_;
                this->society_ = nullptr;
                std::cout << "Success!\n\n" << std::flush;
            }
            break;
        }
        case 0: {
            std::cout << "Peace out! B-)" << std::endl;
            this->running_ = false;
            break;
        }
        default: {
            std::cerr << "\"" << command << "\" is an invalid command.\n\n" << std::flush;
            break;
        }
    }
}
void Driver::start() {
    this->running_ = true;
    int command;
    while(this->running_) {
        this->menu();
        try{
            command = Driver::getIntFromUser("Enter an menu option by number: ");
            std::cout << std::endl;
            this->run(command);
        } catch(std::invalid_argument e) {
            std::cerr << "Menu options can only be selected by their number.\n"
                    "Please enter an integer number corresponding to the menu option you'd like to select.\n\n"
                    << std::flush;
        }
    }
}
