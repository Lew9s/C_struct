#include<stdio.h>
typedef double ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}CirLinkListHeader;
//��ͷ����ѭ��������,ֻ��βָ����� 
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
		//��s->nextָ��ͷ��㣬����ͷ���ĵ�ַ��ֵ��s->next����
		s->next=rear->next;
		//��rear->nextָ��s,����sֵ��ֵ��rear->next
		rear->next=s;
		//��rearָ��s,����s��ֵ��ֵ��rear
		rear=s; 
 	}
 	return rear;
}
/*
��������ϣ�������ɴ�ͷ����ѭ��������������ĸ����������㷨��������룬
���ϻ����� 
*/
