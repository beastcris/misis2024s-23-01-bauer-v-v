add_library(stackarr stackarr.cpp stackarr.hpp)


target_link_libraries(stackarr complex)

set_property(TARGET stackarr PROPERTY CXX_STANDARD 20)