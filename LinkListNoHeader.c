#include<stdio.h>
typedef char ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkListNoHeader;
//����ͷ���ĵ�����
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
	if(!L) {printf("��գ�����ȡֵ\n");   return 0;}
	if(i<1){printf("λ�ò���������ȡֵ\n");   return 0;}
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
	printf("λ�ò���������ȡֵ\n");   
	return 0;
}
int Locate(LinkListNoHeader *L,ElemType x);//��ֵ����
int Insert(LinkListNoHeader *L,int i,ElemType x) {
	LinkListNoHeader *s,*p;
	int count;
	//�ڱ�L�ĵ�iλ���ϲ���Ԫ��x 
	if(i<1){ printf("λ�ò��������ܲ���\n");  return 0;	}
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
	//ɾ����L��iλ���ϵĽ�㣬���ɾ���ɹ����򽫱�ɾ������е�Ԫ�ظ�ֵ��*x�����ҷ���1
	//���򣬷���0 
	 ....�Լ���ɴ��� 
}
//�ٶ��������������� 



