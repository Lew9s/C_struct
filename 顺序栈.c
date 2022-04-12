#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct{                //共享栈 
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack;

void InitStack(SqStack S){    //初始化栈 
	S.top=-1;                 //初始化栈顶指针 
}

int StackEmpty(SqStack S){    //判断栈空 
	if(S.top==-1)
	    return 1;
	else
	    return 0;
}

int Push(SqStack S,ElemType x){     //新元素进栈 
	if(S.top==MaxSize-1)
	    return 0;
	S.top++;
	S.top=x; 
	return 1;
}

int Pop(SqStack S){                 //栈顶元素出栈并返回 
	ElemType x;
	if(S.top==-1)
	    return 0;
	x=S.data[S.top];
	S.top=S.top-1;
	return x;
}

int GetTop(SqStack S){              //读取栈顶元素 
	if(S.top==-1)
	    return 0;
	ElemType x=S.data[S.top];
	return x;
} 

void InitShStack(ShStack S){        //初始化共享栈 
	S.top0=-1;
	S.top1=MaxSize;
}

int main(){
	SqStack S;
	InitStack(S);
}
