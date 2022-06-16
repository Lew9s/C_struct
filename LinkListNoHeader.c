#include<stdio.h>
typedef char ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkListNoHeader;
//不带头结点的单链表
LinkListNoHeader *IniLinkList() {
	LinkListNoHeader *L=NULL;
	return L; 
}
LinkListNoHeader * CreateLinkList(ElemType a[],int n){
	LinkListNoHeader *L=NULL,*s;
	int i;
	for(i=0;i<n;++i){
		s=(LinkListNoHeader *)malloc(sizeof(struct Node));
		s->data=a[i];
		s->next=L;
		L=s;
	}
	return L;	
}
void Release(LinkListNoHeader *L){
	LinkListNoHeader *p=L;
	while(p){
		L=L->next;
		free(p);
		p=L;
	}
}
int Length(LinkListNoHeader *L){
	int count=0;
	LinkListNoHeader *p=L;
	while(p){
		count++;
		p=p->next;
	}
}
int Empty(LinkListNoHeader *L){
	return (!L?1:0);
}
int Get(LinkListNoHeader *L,int i,ElemType *x){
	if(!L) {printf("表空，不能取值\n");   return 0;}
	if(i<1){printf("位置不当，不能取值\n");   return 0;}
	int count=1;
	LinkListNoHeader *p =L;
	while(p&&count<i){
		count++;
		p=p->next;
	}
	if(p){
		*x=p->data;
		return 1;
	}
	printf("位置不当，不能取值\n");   
	return 0;
}
int Locate(LinkListNoHeader *L,ElemType x);//按值查找
int Insert(LinkListNoHeader *L,int i,ElemType x) {
	LinkListNoHeader *s,*p;
	int count;
	//在表L的第i位置上插入元素x 
	if(i<1){ printf("位置不当，不能插入\n");  return 0;	}
	if(i==1){
		s=(LinkListNoHeader *)malloc(sizeof(LinkListNoHeader));
		s->data=x;
		s->next=L;
		L=s;
		return 1;
	}
	....
}
int Delete(LinkListNoHeader *L,int i,ElemType *x){
	//删除表L第i位置上的结点，如果删除成功，则将被删除结点中的元素赋值给*x，并且返回1
	//否则，返回0 
	 ....自己完成代码 
}
//再定义主函数，测试 



