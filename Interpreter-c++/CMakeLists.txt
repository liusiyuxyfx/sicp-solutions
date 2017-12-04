cmake_minimum_required(VERSION 3.5.1)
project(Interpreter_c__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/Allocator.cpp
        src/Allocator.h
        src/BuilIn.h
        src/BuiltIn.cpp
        src/Evaluator.cpp
        src/Evaluator.h
        src/Interpreter.cpp
        src/Interpreter.h
        src/Iota.h
        src/main.cpp
        src/Parser.cpp
        src/Parser.h
        src/SymbolTable.cpp
        src/SymbolTable.h)

add_executable(Interpreter_c__ ${SOURCE_FILES})
