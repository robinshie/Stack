//
//  main.cpp
//  Stack
//
//  Created by robin on 15/4/11.
//  Copyright (c) 2015年 robin. All rights reserved.
//
//#include <stdio.h>
//#include <stdlib.h>
//#define STACK_INIT_SIZE 100
//#define STACKINCRETMENT 10
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0

//#define INFEASIBLE -1
//#define OVERFLOW -2
//typedef int Status;
//typedef int SElemYype;
//typedef struct{
   // SElemYype *base;
    //SElemYype *top;
    //int stacksize;

//}SqStack;
#include<RobinStack.h>
Status InitStack(SqStack &S){
    S.base=(SElemYype *)malloc(STACK_INIT_SIZE*sizeof(SElemYype));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}
Status GetTop(SqStack &S,SElemYype &e)
{
    
    if (S.top==S.base)  return ERROR;
    e=*(S.top-1);
    return OK;
}

Status Push(SqStack &S,SElemYype e)
{
    if (S.top-S.base>=S.stacksize){
    S.base=(SElemYype *)realloc(S.base,(STACK_INIT_SIZE+STACKINCRETMENT)*sizeof(SElemYype));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base+S.stacksize;
    S.stacksize+=STACKINCRETMENT;
    }
    *S.top++ = e;
    
    return OK;

}
Status Pop(SqStack &S,SElemYype &e)
{
    
    if(S.top==S.base) return ERROR;
    
    e=*(--S.top);


    return e;
}
Status StackEmpty(SqStack &S)
{
    if(S.top==S.base) return OK;
    else return FALSE;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    SqStack S;
    int n,e;
    int u; 
    InitStack(S);
    scanf("%d",&n);
    scanf("%d",&u);
    while (n) {
        Push(S,n%u);
        n=n/u;
    }
    
    while (!StackEmpty(S)) {
        
        e=Pop(S,e);
        printf("%d",e);
	
    }
    printf("\n");
    return 0;
}
