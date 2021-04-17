cmake_minimum_required(VERSION 3.10)

#set the project name
project(cppstack)

#headers
include_directories(./)

#set sources
set(SOURCES main.cpp test_empty.cpp)

set(POST_SRC   postfixexp.cpp)
set(PRE_SRC    prefixexp.cpp)
set(PAREN_SRC  parencheck.cpp)
set(CALC_SRC   calculator.cpp)

#add executable
add_executable(cppstack ${SOURCES})

add_executable(calculator ${CALC_SRC})
add_executable(postfix    ${POST_SRC})
add_executable(prefix     ${PRE_SRC})
add_executable(parencheck ${PAREN_SRC})
