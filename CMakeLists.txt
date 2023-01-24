cmake_minimum_required(VERSION 3.23)
project(LP1AED1_Projeto C)

set(CMAKE_C_STANDARD 99)

add_executable(LP1AED1_Projeto main.c bipolar.c bipolar.h func_chars.h func_chars.c func_ints.c func_ints.h
        key_holder.c key_holder.h keychain_list.c keychain_list.h user.c user.h user_list.c user_list.h)
