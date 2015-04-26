cmake_minimum_required(VERSION 3.1)
project(socsim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(HEADER_FILES
    include/Society.h
    include/Dispatcher.h
    include/Person.h
    include/Relationship.h
    include/MessageType.h
    include/RelationshipType.h
    include/PersonNotFoundException.h
    include/MessageTypeNotFoundException.h
    include/DuplicateRelationshipException.h
    include/DuplicateMessageTypeException.h
    include/Importer.h)

set(SOURCE_FILES
    main.cpp
    src/Society.cpp
    src/Dispatcher.cpp
    src/MessageType.cpp
    src/Person.cpp
    src/Relationship.cpp
    src/RelationshipType.cpp
    src/Importer.cpp)

add_executable(socsim ${SOURCE_FILES} ${HEADER_FILES})