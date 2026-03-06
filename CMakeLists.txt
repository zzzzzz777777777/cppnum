cmake_minimum_required(VERSION 3.24)

project(cppnum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES
    src/main.cpp
    src/num_operations.cpp
)

# Header files
set(HEADERS
    include/num_operations.h
)

# Create library target
add_library(cppnum STATIC ${SOURCES} ${HEADERS})
target_include_directories(cppnum PUBLIC include)

# Build tests if needed
enable_testing()
add_executable(cppnum_test tests/test_main.cpp)
target_link_libraries(cppnum_test PRIVATE cppnum)
add_test(NAME CppNumTests COMMAND cppnum_test)

# Installation rules
install(TARGETS cppnum
    EXPORT cppnum-targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

# Export the targets
install(EXPORT cppnum-targets
    FILE cppnum-targets.cmake
    NAMESPACE cppnum::
    DESTINATION lib/cppnum
)