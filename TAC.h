//
// Created by Carol on 2021/1/23.
//

#ifndef COMPILER_TAC_H
#define COMPILER_TAC_H
#include"parse.h"
typedef enum{printfs,scanfs,if_fs,asns,labss,muls,adds,
    minus,callfuns,definefuns,mainfuns,mainfuns_end,
    definefuns_end,defineparas,ifstarts,ifends,whilestarts,
    whileends,forstarts,forends,divs,mods,if_eqs,not_eqs,
    bigs,big_eqs,smas,sma_eqs,returns,jumps,args,begin_args,
    funreturns,add_nexts,minus_nexts,for_cmp}opkinds;///主要操作


typedef enum {emptys,consts,strings}addrkinds; ///限定地址类型

typedef struct
{
    addrkinds kind;
    char name[20];
}address;  ///地址结构


typedef struct fourvarcode
{
    opkinds op;
    address addr1;
    address addr2;
    address addr3;
    struct fourvarcode* next;
}fourvarcode; ///四元表达式的结构(实际就是一个链表)


extern treenode *tree_gen;
extern tokentype token;
extern char* tokenstring();
#endif //COMPILER_TAC_H
