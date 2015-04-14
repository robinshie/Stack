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
typedef int Status;
typedef int SElemYype;
typedef struct{
	    SElemYype *base;
	        SElemYype *top;
		    int stacksize;

}SqStack;
Status InitStack(SqStack &S);
Status GetTop(SqStack &S,SElemYype &e);
Status Push(SqStack &S,SElemYype e);
Status Pop(SqStack &S,SElemYype &e);
Status StackEmpty(SqStack &S);
Status ClearnStack(SqStack &S);
Status DestoryStack(SqStack &S);
