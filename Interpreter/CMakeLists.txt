cmake_minimum_required(VERSION 3.7)
project(Interpreter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/Allocator.c
        src/Allocator.h
        src/BuilIn.h
        src/BuiltIn.c
        src/Evaluator.c
        src/Evaluator.h
        src/Interpreter.c
        src/Interpreter.h
        src/Iota.h
        src/main.c
        src/Parser.c
        src/Parser.h
        src/SymbolTable.c
        src/SymbolTable.h)

add_executable(Interpreter ${SOURCE_FILES})