#include<stdio.h>
typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkList;
//带头结点的单链表
LinkList *IniLinkList(){//置空表
	LinkList *L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
	return L;
} 
LinkList *Create(ElemType a[],int n){
	LinkList *L,*r,*s;
	int i=0;
	r=L=(LinkList *)malloc(sizeof(LinkList));
	for(;i<n;++i){
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return L;
}
int Length(LinkList *L){
	LinkList *p=L->next;
	int count=0;
	while(p){
		count++;
		p=p->next;
	}
	return count;
}
int Empty(LinkList *L){
	return (L->next==0?1:0);
}
int Get(LinkList *L,int i,ElemType *x){
	LinkList *p=L->next;
	int count=1;
	while(p&&count<i){
		count++;
		p=p->next;
	}
	if(!p) {  printf("位置不当，无法取值\n"); return 0;}
	*x=p->data;
	return 1;
}
int Locate(LinkList *L,ElemType x){
	LinkList *p=L->next;
	int count=1;
	while(p&&p->data!=x){
		p=p->next;
		count++;
	}
	/*if(p) return count;
	else 0;*/
	return (p?count:0);
}
int Insert(LinkList *L,int i,ElemType x){
	//在表L的第i位置上插入元素x
	if(i<1) { printf("位置不当，不能插入\n"); return 0;}
	LinkList *p=L;
	int count=0;
	while(p&&count<i-1){
		p=p->next;
		count++;
	}
	if(!p){printf("位置不当，不能插入\n"); return 0;}
	LinkList *s=(LinkList *)malloc(sizeof(LinkList)); 
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}
void printLinkList(LinkList *L){
	LinkList *p=L->next;
	while(p){
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
}
//课外完成删除函数的定义
int main(){
	LinkList *L1,*L2;
	//创建空表L1
	L1=IniLinkList();
	printf("%d,%d",Empty(L1),Length(L1));
	Insert(L1,1,10);
	Insert(L1,1,20); 
	Insert(L1,2,30);
	printLinkList(L1);
	ElemType a[]={10,20,30,40,50};
	L2=Create(a,5);
	printLinkList(L2);
	int m1,m2;
	m1=Get(L2,4,&m2); 
	printf("%d,%d\n",m1,m2);
	m1=Get(L2,6,&m2); 
	printf("%d,%d\n",m1,m2); 
	m1=Locate(L2,20);
	printf("%d\n",m1);
	m1=Locate(L2,200);
	printf("%d\n",m1);
	
	return 0;
} 
