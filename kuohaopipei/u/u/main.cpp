//
//  main.cpp
//  u
//
//  Created by robin on 15/4/11.
//  Copyright (c) 2015年 robin. All rights reserved.
//

#include "RobinStack.h"
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
        if(S.top==S.base) return OVERFLOW;
//        S.top--;
        e=*(--S.top);
    
    return OK;
    
}
Status StackEmpty(SqStack &S)
{
    if(S.top==S.base) return OK;
    else return FALSE;
}

int main()
{//⼦子函数声明
   
    SqStack s;//初始化空栈
    InitStack(s);
    char ch[100],*p;int e;
    p=ch;
    printf("输⼀一个含义有()[]{}的括号表达式:\n");
    gets(ch);
    while(*p)
    {
        switch (*p)
        {
            case '{':
            case '[':
            case '(': Push(s,*p++);break;//只要是左括号就⼊入栈 case '}':
            case '}':
            case ']':
            case ')':Pop(s,e);
                if ((e=='{' && *p=='}') || (e=='[' && *p==']') || (e=='(' && *p==')'))
                    p++;
                else
                {
                    printf("括号不匹配!\n");exit(OVERFLOW);} break;
            default :p++;
                
        }
    }
    if (StackEmpty(s))
        printf("括号匹配成功\n"); else
            printf("缺少右括号!\n");
    printf("\n");
    
    
    
    
    return 0;
}
