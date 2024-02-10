add_library(stack stackarr.cpp stackarr.hpp)


target_link_libraries(stack complex)

set_property(TARGET stack PROPERTY CXX_STANDARD 20)


