add_executable (test_stack test_stack.cpp)
target_link_libraries(test_stack stack)

add_executable(test_stacklist test_stacklist.cpp)
target_link_libraries(test_stacklist stacklst)

add_executable(test_queue test_queue.cpp)
target_link_libraries(test_queue queuelst)