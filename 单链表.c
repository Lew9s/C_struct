#include<stdio.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode));   //����һ��ͷ��� 
	if(L==NULL)                        //�ڴ治�㣬����ʧ�� 
	    return 0;
	L->next=NULL;                      //ͷ���֮����ʱ��û�нڵ� 
	return 1;
}

int Empty(LinkList L){                //�жϵ������Ƿ�Ϊ�գ���ͷ��㣩 
	if(L->next==NULL)
	    return 1;
	else
	    return 0;
}

int Listinsert(LinkList L,int i,int e){           //�ڵ�i��λ�ò���Ԫ��e 
	if(i<1)
	    return 0;
	LNode *p;                               //ָ��pָ��ǰɨ��Ľڵ� 
	int j=0;                                //��ǰpָ��Ľڵ��λ�� 
	p=L;                                    //Lָ��ͷ��㣬Ϊ��0���ڵ� 
	while (p!=NULL && j<i-1){                 //ѭ���ҵ���i-1���ڵ� 
		p=p->next;
		j++;
	}
	if(p==NULL)                             //iֵ���Ϸ�����i-1���ڵ�Ϊ�գ� 
	    return 0;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
} 

int InsertNextNode(LNode *p,ElemType e){    //����������p�ڵ���������e 
	if(p==NULL)
	    return 0;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
	    return 0;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}

int InsertPriorNode(LNode *p,ElemType e){   //ǰ���������p�ڵ�ǰ����Ԫ��e 
	if(p==NULL)
	    return 0;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
	    return 0;
	s->next=p->next;                        //s����p�ڵ�� 
	p->next=s;
	s->data=p->data;                        //p��Ԫ�ظ�ֵ��s 
	p->data=e;                              //p��Ԫ�ظ���Ϊe 
	return 1;
}

int LinkDelete(LinkList L,int i){           //ɾ����i���ڵ� 
	ElemType e; 
	if(i<1)
	    return 0;
	LNode *p;                               //ָ��pָ��ǰɨ��Ľڵ� 
	int j=0;                                //��ǰpָ��Ľڵ��λ�� 
	p=L;                                    //Lָ��ͷ��㣬Ϊ��0���ڵ� 
	while (p!=NULL && j<i-1){               //ѭ���ҵ���i-1���ڵ� 
		p=p->next;
		j++;
	}
	if(p==NULL)
	    return 0;
	if(p->next==NULL)                       //��i���ڵ㲻���� 
	    return 0;
	LNode *q=p->next;                       //��qָ��ɾ���ڵ� 
	e=q->data;                              //��e����Ԫ��ֵ 
	p->next=q->next;                        //��q�ڵ�����жϿ� 
	free(q);
	return e;
} 

LinkList List_TailInsert(LinkList L){       //β�巨���������� 
	int x;                                        
	LNode *s,*r=L;                            //rΪ��βָ�� 
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;                              //β���ָ���ÿ� 
	return L;
}

LinkList List_HeadInsert(LinkList L){       //ͷ�巨���������� 
	LNode* s;
	int x;
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}

int main(){
	LinkList L;                        //����һ��ָ�������ָ�� 
	//��ʼ���ձ� 
	InitList(L);
	return 0;
}
