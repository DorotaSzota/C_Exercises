cmake_minimum_required(VERSION 3.27)
project(Zadania_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Zadania_1
        Zad_1_.c

)

add_executable(Zad_1_ Zad_1_.c
        Zad_2_.c
        Zad_3_.c
        Zad_4_.c
        Zad_5_.c
        Zad_6_.c)
add_executable(Zad_2_ Zad_2_.c)
add_executable(Zad_3_ Zad_3_.c)

add_executable(Zad_4_ Zad_4_.c)
add_executable(Zad_5_ Zad_5_.c)
add_executable(Zad_6_ Zad_6_.c)
