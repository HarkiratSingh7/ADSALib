# samples/linklistdemo
include_directories(${ADSALib_SOURCE_DIR}/Algolib/include)
link_directories(${ADSALib_SOURCE_DIR}/Algolib/src)
add_executable(LinkedListDemo main.cpp)
target_link_libraries(LinkedListDemo INTERFACE Algolib)