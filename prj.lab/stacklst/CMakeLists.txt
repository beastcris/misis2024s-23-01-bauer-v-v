add_library(stacklst stacklst.cpp stacklst.hpp)
target_link_libraries(stacklst complex)

set_property(TARGET stacklst PROPERTY CXX_STANDARD 20)
