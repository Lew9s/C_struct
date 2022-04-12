#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct{                //����ջ 
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack;

void InitStack(SqStack S){    //��ʼ��ջ 
	S.top=-1;                 //��ʼ��ջ��ָ�� 
}

int StackEmpty(SqStack S){    //�ж�ջ�� 
	if(S.top==-1)
	    return 1;
	else
	    return 0;
}

int Push(SqStack S,ElemType x){     //��Ԫ�ؽ�ջ 
	if(S.top==MaxSize-1)
	    return 0;
	S.top++;
	S.top=x; 
	return 1;
}

int Pop(SqStack S){                 //ջ��Ԫ�س�ջ������ 
	ElemType x;
	if(S.top==-1)
	    return 0;
	x=S.data[S.top];
	S.top=S.top-1;
	return x;
}

int GetTop(SqStack S){              //��ȡջ��Ԫ�� 
	if(S.top==-1)
	    return 0;
	ElemType x=S.data[S.top];
	return x;
} 

void InitShStack(ShStack S){        //��ʼ������ջ 
	S.top0=-1;
	S.top1=MaxSize;
}

int main(){
	SqStack S;
	InitStack(S);
}
