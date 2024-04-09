add_executable (test_stack test_stack.cpp)
target_link_libraries(test_stack stackarr)

add_executable(test_stacklist test_stacklist.cpp)
target_link_libraries(test_stacklist stacklst)

add_executable(test_stacklstt test_stacklstt.cpp)
target_link_libraries(test_stacklstt stacklstt)
target_link_libraries(test_stacklstt complex)

add_executable(test_queue test_queue.cpp)
target_link_libraries(test_queue queuelst)

add_executable(test_queuearr test_queuearr.cpp)
target_link_libraries(test_queuearr queuearr)

add_executable(test_queuelstpr test_queuelstpr.cpp)
target_link_libraries(test_queuelstpr queuelstpr)

add_executable(test_bitset test_bitset.cpp)
target_link_libraries(test_bitset bitset)

add_executable(general_test general_test.cpp)