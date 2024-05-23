cmake_minimum_required(VERSION 3.27)
project(Zadania_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Zadania_1
        Zadania_1/Zad_1_.c

)

add_executable(Zad_1_ Zadania_1/Zad_1_.c
        Zadania_1/Zad_2_.c
        Zadania_1/Zad_3_.c
        Zadania_1/Zad_4_.c
        Zadania_1/Zad_5_.c
        Zadania_1/Zad_6_.c
        Zadania_2/Zad_2_.c
        Zadania_2/Zad_1_.c
        Zadania_3/Zad_1_.c
        Zadania_4/Zad_1_.c
        Zadania_4/Zad_2_.c
        Zadania_4/Zad_3_.c
        Zadania_3/Zad_2_.c
        Zadania_5/Zad_1_.c
        Zadania_5/Zad_2_.c
)

add_executable(Zad_2_ Zadania_1/Zad_2_.c
        Zadania_2/Zad_2_.c)
add_executable(Zad_3_ Zadania_1/Zad_3_.c
        Zadania_2/Zad_2_.c)
add_executable(Zad_4_ Zadania_1/Zad_4_.c
        Zadania_2/Zad_2_.c)
add_executable(Zad_5_ Zadania_1/Zad_5_.c
        Zadania_2/Zad_2_.c)
add_executable(Zad_6_ Zadania_1/Zad_6_.c
        Zadania_2/Zad_2_.c)
add_executable(Zad_3_1_ Zadania_3/Zad_1_.c)
add_executable(Zad_4_1_ Zadania_4/Zad_1_.c)
add_executable(Zad_4_2_ Zadania_4/Zad_2_.c)
add_executable(Zad_4_3_ Zadania_4/Zad_3_.c)
add_executable(Zad_3_2_ Zadania_3/Zad_2_.c)


add_executable(Zad_5_1_ Zadania_5/Zad_1_.c)
add_executable(Zad_5_2_ Zadania_5/Zad_2_.c)
