# CSCI 2270 Final Project

**Brandon Eric Phillips**

##  IMDB: The Missing Link

...is a trivia game using data from the Internet Movie Database where the user is given information about a(n) actor,
actress, movie, director, etc and they must guess who it is. The data is exported from IMDB into text files, which
are parsed into a graph. The graph will consist of nodes that represent some sort of entity such as an actor, actress,
movie, director, etc. and edges that represent some sort of relationship between entities such as directed, acted in,
etc.

### Dependencies

### System Requirements

 * cmake

### Building

    $ cmake --build ./build --target all
    
Binary outputted as `./build/project`

### Group Members

 * @bericp1 (Brandon Phillips)

### Contributors

### TODO

 * Download IMDB text files
 * Format files for easier consumption
 * Parse all text files into a graph
 * Based on memory consumption/processing time, only use a subset of IMDB data
 * Randomly select a node in the graph
 * Show `n` adjacent nodes (`n` varies with difficulty)
 * Show 4 to 5 possible answers (multiple choice)
 * Score system