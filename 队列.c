#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;

void InitQueue(SqQueue Q){
	Q.front=Q.rear=0;
}

int QueueEmpty(SqQueue Q){
	if(Q.rear=Q.front)
	    return 1;
	else
	    return 0;
}

int EnQueue(SqQueue Q,ElemType x){
	if((Q.rear+1)%MaxSize==Q.front)
	    return 0;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	return 1;
}

int DeQueue(SqQueue Q){
	if(Q.front==Q.rear)
	    return 0;
	ElemType x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return 1; 
}

int GetHead(SqQueue Q){
	if(Q.front==Q.rear)
	    return 0;
	ElemType x=Q.data[Q.front];
	return x;
}

int main(){
	SqQueue Q;
	InitQueue(Q);
}
