#include<stdio.h>
typedef struct BitNode{
	ElemType data;
	struct BitNode *lchild,*rchlid;
}BitNode,*Bitree;

void PreOrder(Bitree T){        //��������������ң� 
	if(T != NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchlid);
	}
} 

void InOrder(Bitree T){        //�������������ң� 
	if(T != NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchlid);
	}
} 

void PostOrder(Bitree T){        //�������������ң� 
	if(T != NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchlid);
		visit(T); 
	}
} 
