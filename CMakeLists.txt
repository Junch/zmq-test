cmake_minimum_required (VERSION 3.5)

project (zmq-req CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
    # make the Release version create a PDB
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    # minimize the size or the resulting EXE
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(3rdparty/libzmq)
add_subdirectory(3rdparty/cppzmq)

add_library(rapidjson INTERFACE)
target_include_directories(rapidjson INTERFACE "3rdparty/rapidjson/include")

set(SRCFILES zmq-req.cpp)
add_executable(zmq-req ${SRCFILES})
target_link_libraries(zmq-req PRIVATE cppzmq rapidjson)
