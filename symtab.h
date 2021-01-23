//
// Created by Carol on 2021/1/23.
//

#ifndef COMPILER_SYMTAB_H
#define COMPILER_SYMTAB_H
#include "global.h"
#include "parse.h"

extern treenode *tree_gen;


typedef struct symboltable
{
    char name[20]; //名字
    char type[10]; //类型
    char val[10];  //值
    int  location;
    struct symboltable* next;
}symboltable;

/*extern lquad tac_head;
 哈希表的大小，这里为大于200的最小素数 Loudon P229*/
/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

#endif //COMPILER_SYMTAB_H
