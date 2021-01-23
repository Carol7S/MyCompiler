//
// Created by Carol on 2021/1/23.
//
#include"global.h"
#include"optimize_TAC.h"
void start_optimize();
void optimer_tac();
void print_optimize_tac();

void start_optimize()
{
    optimer_tac();
    print_optimize_tac();
}
void optimer_tac()
{
    fourvarcode* t=tac_head->next;
    fourvarcode* p;
    fourvarcode* q;
    p=t->next;
    q=p->next;
    while(q!=NULL)
    {
        if(p->op==asns) //  asns 赋值
        {
            if(q->op==asns)
            {
                char a[20];
                strcpy(a,p->addr2.name);
                if(strcmp(p->addr2.name,q->addr1.name)==0 && a[0]=='t' && a[1]=='#')
                {
                    strcpy(p->addr2.name,q->addr2.name);
                    p->next=q->next;
                    free(q);
                    q=p->next;
                }
                else
                {
                    t=t->next;
                    p=p->next;
                    q=q->next;
                }
            }

            else if(q->op!=asns) ///p可能需要删掉  比如return 0 的多于
            {
                char a[10],b[20],c[20];
                strcpy(a,p->addr1.name);
                strcpy(b,p->addr2.name);
                strcpy(c,q->addr3.name);
                if(strcmp(p->addr2.name,q->addr1.name)==0&&b[0]=='t'&&b[1]=='#'&&(c[0]=='\0'||a[1]=='#')&&q->op!=if_fs)
                {
                    strcpy(q->addr1.name,p->addr1.name);///将asn的值给下一句
                    t->next=p->next;
                    free(p);
                    p=t->next;
                    q=q->next;
                }
                else
                {
                    t=t->next;
                    p=p->next;
                    q=q->next;
                }
            }
        }
        else if(p->op!=asns)  ///如果不是赋值语句，那么它的下一句是赋值语句的话，且有运算
        {
            if(q->op==asns)
            {
                if(p->addr3.kind!=emptys)
                {
                    char a[20];
                    strcpy(a,p->addr3.name);
                    if(strcmp(p->addr3.name,q->addr1.name)==0&&a[0]=='t'&&a[1]=='#')
                    {
                        strcpy(p->addr3.name,q->addr2.name);///将赋值提前
                        p->next=q->next;
                        free(q);
                        q=p->next;
                    }
                    else ///如果不是运算 --继续执行
                    {
                        t=t->next;
                        p=p->next;
                        q=q->next;
                    }
                }
                else///如果不是运算 --继续遍历
                {
                    t=t->next;
                    p=p->next;
                    q=q->next;
                }
            }
            else  ///下一句也不是赋值语句，那么肯定继续搜索，没法简化
            {
                t=t->next;
                p=p->next;
                q=q->next;
            }
        }

    }
}
///输出简化后的四元式
void print_optimize_tac()
{
    fourvarcode* t=tac_head->next;
    while(t!=NULL)
    {
        if(t->op==ifstarts||t->op==ifends||t->op==mainfuns_end||t->op==mainfuns||t->op==forstarts||t->op==forends||t->op==defineparas
           ||t->op==whilestarts ||t->op==whileends)
        {
            t=t->next;
        }
        else
        {
            printf("(");
            printf("%s ,",opkinds_string(t->op));
            if(t->addr1.kind==emptys)
                printf("_ ,");
            else
                printf("%s ,",t->addr1.name);

            if(t->addr2.kind==emptys)
                printf("_ ,");
            else
                printf("%s ,",t->addr2.name);

            if(t->addr3.kind==emptys)
                printf("_ ,");
            else
                printf("%s ,",t->addr3.name);

            t=t->next;
            printf(")");
            printf("\n");
        }
    }
}
