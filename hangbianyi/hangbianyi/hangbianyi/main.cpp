//
//  main.cpp
//  hangbianyi
//
//  Created by robin on 15/4/12.
//  Copyright (c) 2015年 robin. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCRETMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define INFEASIBLE -1
#define OVERFLOW -2
typedef int SElemYype;
typedef struct{
    SElemYype *base;
    SElemYype *top;
    int stacksize;
    
}SqStack;
void InitStack(SqStack &S);
void Push(SqStack &S,char e);
char Pop(SqStack &S,char &e);
int StackEmpty(SqStack &S);
void ClearnStack(SqStack &S);

void InitStack(SqStack &S){
    S.base=(SElemYype *)malloc(STACK_INIT_SIZE*sizeof(SElemYype));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
}


void Push(SqStack &S,char e)
{
    if (S.top-S.base>=S.stacksize){
        S.base=(SElemYype *)realloc(S.base,(STACK_INIT_SIZE+STACKINCRETMENT)*sizeof(SElemYype));
        if(!S.base) exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCRETMENT;
    }
    *S.top++ = e;
    
    
    
    
}
char Pop(SqStack &S,char &e)
{
    if(S.top==S.base) return OVERFLOW;
        e=*--S.top;
    
    return e;
    
}
int StackEmpty(SqStack &S)
{
    if(S.top==S.base) return OK;
    else return FALSE;
}
void ClearnStack(SqStack &S){
    S.base=S.top;
    
}

int main(int argc, const char * argv[]) {
    SqStack s;//初始化空栈
    InitStack(s);
    char ch;char e;
    printf("请输入文本\n");
    ch=getchar();
    while (ch!=EOF) {
        while (ch!=EOF&&ch!='\n') {
            switch (ch) {
                case '#':Pop(s,e);break;
                case '@':ClearnStack(s);
                    
                default:Push(s,ch);
                    
                    Pop(s,e);
                    printf("%c",e);
        
            }
        ch=getchar();
        }
        ClearnStack(s);
        if(ch!=EOF)
            ch=getchar();
        Pop(s, e);
        
        
    }
    
    
}
