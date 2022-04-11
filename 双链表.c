#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinklist; 

int InitDLinkList(DLinklist L){     //初始化双链表 
	L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL)            //内存不足 
	    return 0;
	L->prior=NULL;         //头结点的前驱节点永远指向null 
	L->next=NULL;          
	return 1;
}

int Empty(DLinklist L){             //判断双链表是否为空 
	if(L->next==NULL)
        return 1;
    else
        return 0;
}

int InsertNextDNode(DNode *p,DNode *s){     //在p结点之后插入s结点 
	if(p==NULL || s==NULL)   //传入参数非法 
	    return 0;
	s->next=p->next;
	if(p->next!=NULL)        //如果p结点有后继结点 
	    p->next->prior=s;
	s->prior=p;
	p->next=s;
	return 1;
} 

int DeleteNextDNode(DNode *p){              //删除p结点的后继结点 
	if(p==NULL)
        return 0;
    DNode *q=p->next;                       //找到p的后继结点q 
    if(q==NULL)
        return 0;                           //p没有后继结点 
    p->next=q->next;
    if(q->next!=NULL)                       //q结点不是最后一个结点 
        q->next->prior=p;
    free(p);                                //释放空间 
    return 1;
}

int main(){
	DLinklist L;
	InitDLinkList(L);
} 

