cmake_minimum_required (VERSION 3.5)

project (zmq-req CXX)

if(WIN32)
    # make the Release version create a PDB
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    # minimize the size or the resulting EXE
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2")
endif()

add_subdirectory(3rdparty/libzmq)
add_subdirectory(3rdparty/cppzmq)
set(SRCFILES zmq-req.cpp)
add_executable(zmq-req ${SRCFILES})
target_link_libraries(zmq-req PRIVATE cppzmq)
