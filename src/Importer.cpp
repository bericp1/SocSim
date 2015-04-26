#include <cstdio>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "Importer.h"
#include "Society.h"

const std::string Importer::res_directory = "./res/";
const std::string Importer::message_types_filename = "message_types.json";
const std::string Importer::people_filename = "people.json";
const std::string Importer::relationship_types_filename = "relationship_types.json";
const std::string Importer::relationships_filename = "relationships.json";

rapidjson::Document* Importer::parseFile(const std::string& filename) {
    FILE* file_pointer = fopen(filename.c_str(), "rb");
    rapidjson::Document* document = new rapidjson::Document;
    char buffer[65536];
    rapidjson::FileReadStream frs (file_pointer, buffer, sizeof(buffer));
    document->ParseStream(frs);
    return document;
}

Society* Importer::importTo(Society* society) {
    Dispatcher* dispatcher = society->getDispatcher();

    rapidjson::Document* message_types_document = Importer::parseFile(Importer::res_directory + Importer::message_types_filename);
    rapidjson::Document* relationship_types_document = Importer::parseFile(Importer::res_directory + Importer::relationship_types_filename);
    rapidjson::Document* people_document = Importer::parseFile(Importer::res_directory + Importer::people_filename);
    rapidjson::Document* relationships_document = Importer::parseFile(Importer::res_directory + Importer::relationships_filename);

    rapidjson::Value::ConstValueIterator itr;
    rapidjson::Value::ConstMemberIterator itr_label;
    rapidjson::Value::ConstMemberIterator itr_prob;
    rapidjson::Value::ConstMemberIterator itr_subprob;
    rapidjson::Value::ConstMemberIterator itr_max;
    rapidjson::Value::ConstMemberIterator itr_name;
    rapidjson::Value::ConstMemberIterator itr_occupation;
    rapidjson::Value::ConstMemberIterator itr_from;
    rapidjson::Value::ConstMemberIterator itr_type;
    rapidjson::Value::ConstMemberIterator itr_to;

    for(itr = message_types_document->Begin(); itr != message_types_document->End(); ++itr) {
        if(itr->IsObject()) {
            itr_label = itr->FindMember("label");
            itr_prob = itr->FindMember("prob");
            itr_max = itr->FindMember("max");
            if(itr_label != itr->MemberEnd() && itr_prob != itr->MemberEnd() && itr_max != itr->MemberEnd()) {
                dispatcher->addMessageType(
                        itr_label->value.GetString(),
                        (float) itr_prob->value.GetDouble(),
                        itr_max->value.GetUint()
                );
            } else if(itr_label != itr->MemberEnd() && itr_prob != itr->MemberEnd()) {
                dispatcher->addMessageType(
                        itr_label->value.GetString(),
                        (float) itr_prob->value.GetDouble()
                );
            } else if(itr_label != itr->MemberEnd() && itr_max != itr->MemberEnd()) {
                dispatcher->addMessageType(
                        itr_label->value.GetString(),
                        itr_max->value.GetUint()
                );
            } else if(itr_label != itr->MemberEnd()) {
                dispatcher->addMessageType(itr_label->value.GetString());
            }
        }
    }

    RelationshipType* relationship_type = nullptr;

    for(itr = relationship_types_document->Begin(); itr != relationship_types_document->End(); ++itr) {
        if(itr->IsObject()) {
            itr_label = itr->FindMember("label");
            itr_prob = itr->FindMember("prob");

            if(itr_label != itr->MemberEnd() && itr_prob != itr->MemberEnd() && itr_prob->value.IsObject()) {
                relationship_type = society->addRelationshipType(itr_label->value.GetString());
                for(itr_subprob = itr_prob->value.MemberBegin(); itr_subprob != itr_prob->value.MemberEnd(); ++itr_subprob) {
                    relationship_type->setProbability(
                            dispatcher->findMessageType(itr_subprob->name.GetString()),
                            (float) itr_subprob->value.GetDouble()
                    );
                }
            }
        }
    }

    for(itr = people_document->Begin(); itr != people_document->End(); ++itr) {
        if(itr->IsObject()) {
            itr_name = itr->FindMember("name");
            itr_occupation = itr->FindMember("occupation");
            if(itr_name != itr->MemberEnd() && itr_occupation != itr->MemberEnd()) {
                society->addPerson(itr_name->value.GetString(), itr_occupation->value.GetString());
            }
        }
    }

    for(itr = relationships_document->Begin(); itr != relationships_document->End(); ++itr) {
        if(itr->IsObject()) {
            itr_from = itr->FindMember("from");
            itr_to = itr->FindMember("to");
            itr_type = itr->FindMember("type");

            if(itr_from != itr->MemberEnd() && itr_to != itr->MemberEnd() && itr_type != itr->MemberEnd()) {
                society->relate(
                        itr_from->value.GetString(),
                        itr_to->value.GetString(),
                        itr_type->value.GetString()
                );
            }
        }
    }

    delete message_types_document;
    delete relationship_types_document;
    delete people_document;
    delete relationships_document;

    return society;
}

Society* Importer::generate() {
    return Importer::importTo(new Society);
}