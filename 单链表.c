#include<stdio.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList L){
	L=(LNode*)malloc(sizeof(LNode));   //分配一个头结点 
	if(L==NULL)                        //内存不足，分配失败 
	    return 0;
	L->next=NULL;                      //头结点之后暂时还没有节点 
	return 1;
}

int Empty(LinkList L){                //判断单链表是否为空（带头结点） 
	if(L->next==NULL)
	    return 1;
	else
	    return 0;
}

int Listinsert(LinkList L,int i,int e){           //在第i个位置插入元素e 
	if(i<1)
	    return 0;
	LNode *p;                               //指针p指向当前扫描的节点 
	int j=0;                                //当前p指向的节点的位序 
	p=L;                                    //L指向头结点，为第0个节点 
	while (p!=NULL && j<i-1){                 //循环找到第i-1个节点 
		p=p->next;
		j++;
	}
	if(p==NULL)                             //i值不合法（第i-1个节点为空） 
	    return 0;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
} 

int InsertNextNode(LNode *p,ElemType e){    //后插操作：在p节点后插入数据e 
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

int InsertPriorNode(LNode *p,ElemType e){   //前插操作：在p节点前插入元素e 
	if(p==NULL)
	    return 0;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
	    return 0;
	s->next=p->next;                        //s插入p节点后 
	p->next=s;
	s->data=p->data;                        //p中元素赋值到s 
	p->data=e;                              //p中元素覆盖为e 
	return 1;
}

int LinkDelete(LinkList L,int i){           //删除第i个节点 
	ElemType e; 
	if(i<1)
	    return 0;
	LNode *p;                               //指针p指向当前扫描的节点 
	int j=0;                                //当前p指向的节点的位序 
	p=L;                                    //L指向头结点，为第0个节点 
	while (p!=NULL && j<i-1){               //循环找到第i-1个节点 
		p=p->next;
		j++;
	}
	if(p==NULL)
	    return 0;
	if(p->next==NULL)                       //第i个节点不存在 
	    return 0;
	LNode *q=p->next;                       //令q指向被删除节点 
	e=q->data;                              //用e返回元素值 
	p->next=q->next;                        //将q节点从链中断开 
	free(q);
	return e;
} 

LinkList List_TailInsert(LinkList L){       //尾插法建立单链表 
	int x;                                        
	LNode *s,*r=L;                            //r为表尾指针 
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;                              //尾结点指针置空 
	return L;
}

LinkList List_HeadInsert(LinkList L){       //头插法建立单链表 
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
	LinkList L;                        //声明一个指向单链表的指针 
	//初始化空表 
	InitList(L);
	return 0;
}
