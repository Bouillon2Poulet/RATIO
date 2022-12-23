cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(Rational_Demo)

# find Rational
# if build as standalone project, find the lib by yourself ...
# if build transitively 

add_executable(Rational_Demo src/main.cpp)                # file to compile and name of the app
target_link_libraries(Rational_Demo PRIVATE Rational)      # lib dependency

# compilation flags
target_compile_features(Rational_Demo PRIVATE cxx_std_17) # use at least c++ 14
if (MSVC)
    target_compile_options(Rational_Demo PRIVATE /W3)
else()
    target_compile_options(Rational_Demo PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()
