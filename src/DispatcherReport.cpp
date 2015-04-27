#include "DispatcherReport.h"
#include "Person.h"

DispatcherReport::~DispatcherReport() {
    this->paths_.clear();
}

void DispatcherReport::recordPath(DispatcherReport::Path path) {
    this->paths_.push_back(path);
}
std::string DispatcherReport::serialize(std::string line_prefix) {
    std::string output = "";
    output += this->message_->serialize(line_prefix);
    output += (line_prefix + "Paths:\n" );
    if(this->paths_.size() == 0)
        output += (line_prefix + "\t(none)\n");
    else {
        PathsIter paths_it;
        PathIter path_it;
        for(paths_it = this->paths_.begin(); paths_it != this->paths_.end(); ++paths_it) {
            output += (line_prefix + "\t");
            if(paths_it->size() == 0)
                output += "(empty)";
            else {
                for(path_it = paths_it->begin(); path_it < paths_it->end(); ++path_it) {
                    if(path_it != paths_it->begin()) output += " -> ";
                    output += (*path_it)->getName();
                }
            }
            output += "\n";
        }
    }
    return output;
}
std::string DispatcherReport::serialize() {
    return this->serialize("");
}
