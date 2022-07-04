cmake_minimum_required(VERSION 3.22)
project(TP_LED_2022 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TP_LED_2022
        abb.h
        fila.h
        principal.c lista_de_usuarios.h)
