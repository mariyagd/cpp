cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(c00/ex01)

add_executable(cpp
        c00/ex01/Contact.class.cpp
        c00/ex01/Contact.class.hpp
        c00/ex01/main.cpp
        c00/ex01/Makefile
        c00/ex01/PhoneBook.class.cpp
        c00/ex01/PhoneBook.class.hpp
        c00/ex01/README.md
        tuto/8.visibility/Sample1.class.cpp
        tuto/6.initialization_list/Sample2.class.cpp
        tuto/6.initialization_list/main.cpp
        tuto/5.this/main.cpp
        c00/ex01/phone.h)
