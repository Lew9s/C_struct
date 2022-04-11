#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinklist; 

int InitDLinkList(DLinklist L){     //��ʼ��˫���� 
	L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL)            //�ڴ治�� 
	    return 0;
	L->prior=NULL;         //ͷ����ǰ���ڵ���Զָ��null 
	L->next=NULL;          
	return 1;
}

int Empty(DLinklist L){             //�ж�˫�����Ƿ�Ϊ�� 
	if(L->next==NULL)
        return 1;
    else
        return 0;
}

int InsertNextDNode(DNode *p,DNode *s){     //��p���֮�����s��� 
	if(p==NULL || s==NULL)   //��������Ƿ� 
	    return 0;
	s->next=p->next;
	if(p->next!=NULL)        //���p����к�̽�� 
	    p->next->prior=s;
	s->prior=p;
	p->next=s;
	return 1;
} 

int DeleteNextDNode(DNode *p){              //ɾ��p���ĺ�̽�� 
	if(p==NULL)
        return 0;
    DNode *q=p->next;                       //�ҵ�p�ĺ�̽��q 
    if(q==NULL)
        return 0;                           //pû�к�̽�� 
    p->next=q->next;
    if(q->next!=NULL)                       //q��㲻�����һ����� 
        q->next->prior=p;
    free(p);                                //�ͷſռ� 
    return 1;
}

int main(){
	DLinklist L;
	InitDLinkList(L);
} 

