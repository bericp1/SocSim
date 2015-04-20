# CSCI 2270 Final Project

**Brandon Eric Phillips**

##  SocSim

...simulates the spread of different kinds of information through a defined community. Using a graph to represent the
community, nodes within the graph represent entities such as people and edges within the graph are directed and
represent the relationships between these people. Each relationship has a type and each type of relationship has
defined weights that represent the possibility a specific type of information will be shared between the two people
that the relationship specifically connects. SocSim generates the community graph from static JSON resources files that
define all people, their relationships, etc. It then asks for a message from the user (and some important meta data
regarding the message) and sends the message through the graph. Stateful information for individual messages such as who
has heard the message, if what they heard differed from the original messsage (e.g. the telephone game), etc. is stored
in a hash table alongside the message, whose data will be formatted and outputted once the message has made its
go-around.

### Dependencies

 * a json library for C++ (TBD)

### System Requirements

 * cmake

### Building

    $ cmake --build ./build --target all
    
Binary outputted as `./build/project`

### Group Members

 * @bericp1 (Brandon Phillips)

### Contributors

### TODO

 * Make up data (JSON res files)
 * Select a JSON lib
 * Build graph classes for representing nodes and relationships
 * Construct graph from imported data
 * I/O controller