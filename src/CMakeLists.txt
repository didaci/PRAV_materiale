cmake_minimum_required(VERSION 4.1)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src
        fizzbuzz/fizzbuzz_1.c
        fizzbuzz/fizzbuzz_2.c
        fizzbuzz/fizzbuzz_3.c
        fizzbuzz/fizzbuzz_4.c
        palindrome/palindrome_1.c
        palindrome/palindrome_2.c
        palindrome/palindrome_3.c)
