cmake_minimum_required(VERSION 3.16)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler main.c global.h scan.h scan.c parse.h parse.c TAC.h TAC.c optimize_TAC.h optimize_TAC.c symtab.h symtab.c asm.h asm.c)