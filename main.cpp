/***
 * Driver file
 *
 */

#include <iostream>
#include "Society.h"
#include "Importer.h"

int main() {
    Society* society = Importer::generate();
    std::cout << society->serialize() << std::endl;
    delete society;
    return 0;
}