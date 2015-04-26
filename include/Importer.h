#ifndef SOCSIM_IMPORTER_H
#define SOCSIM_IMPORTER_H

#include <string>
#include "rapidjson/document.h"
#include "Society.h"

class Importer {
public:
    static const std::string res_directory;
    static const std::string message_types_filename;
    static const std::string people_filename;
    static const std::string relationship_types_filename;
    static const std::string relationships_filename;

    static rapidjson::Document* parseFile(const std::string& filename);

    static Society* generate();
};


#endif //SOCSIM_IMPORTER_H
