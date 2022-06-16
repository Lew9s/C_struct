#include<stdio.h>
typedef double ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}CirLinkListHeader;
//带头结点的循环单链表,只设尾指针变量 
CirLinkListHeader * IniLinkList(){
	CirLinkListHeader *rear =(CirLinkListHeader *)malloc(sizeof(CirLinkListHeader));
	rear->next=rear;
	return rear;	
}
CirLinkListHeader * CreateLinkList(ElemType a[],int n){
	CirLinkListHeader *s,*rear =(CirLinkListHeader *)malloc(sizeof(CirLinkListHeader));
	rear->next=rear;
	int i=0;
	for(;i<n;++i){
		s=(CirLinkListHeader *)malloc(sizeof(CirLinkListHeader));
		s->data=a[i];
		//将s->next指向头结点，即将头结点的地址赋值给s->next变量
		s->next=rear->next;
		//将rear->next指向s,即将s值赋值给rear->next
		rear->next=s;
		//将rear指向s,即将s的值赋值给rear
		rear=s; 
 	}
 	return rear;
}
/*
在这基础上，自行完成带头结点的循环单链表的其它的各个函数的算法及程序代码，
并上机测试 
*/
