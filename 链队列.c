#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LinkNode{        //��ʽ���н�� 
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct{                //��ʽ���� 
	LinkNode *front,*rear;     //��ͷ�Ͷ�βָ�� 
}LinkQueue;

int InitQueue(LinkQueue Q){
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	if(Q.front==NULL)
	    return 0;
	Q.front->next=NULL;
	return 1;
}

int IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear)
	    return 1;
	else
	    return 0;
}

void EnQueue(LinkQueue Q,ElemType x){
	LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=x;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s; 
}

int DeQueue(LinkQueue Q){
	if(Q.front==Q.rear)
	    return 0;
	LinkNode *p=Q.front->next;
	ElemType x=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)                    //�˴�Ϊ���һ�������� 
	    Q.rear=Q.front;
	free(p);
	return x;
}

int main(){
	LinkQueue Q;
	InitQueue(Q);
}
