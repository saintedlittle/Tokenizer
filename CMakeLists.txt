cmake_minimum_required(VERSION 3.26)
project(Tokenizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tokenizer src/main.cpp
        src/util/Token.h
        src/tokenizer/Tokenizer.cpp
        src/tokenizer/Tokenizer.h
        src/util/Error.h
        src/util/Token.cpp
        src/interface/MainWindow.cpp
        src/interface/MainWindow.h
)