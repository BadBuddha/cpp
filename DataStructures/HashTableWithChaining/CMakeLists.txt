cmake_minimum_required (VERSION 2.6)
project (HashTable)

file(GLOB hashTableSource
        "src/*.cpp"
        "include/*.h"
	)

add_executable(HashTable ${hashTableSource})

include_directories ("${PROJECT_SOURCE_DIR}/include/")
