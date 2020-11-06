# samples/linklistdemo
include_directories(${ADSALib_SOURCE_DIR}/Algolib/include)
link_directories(${ADSALib_SOURCE_DIR}/Algolib/src)
add_executable(PriorityQueueDemo main.cpp)
target_link_libraries(PriorityQueueDemo INTERFACE Algolib)