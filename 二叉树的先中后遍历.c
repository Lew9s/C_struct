#include<stdio.h>
typedef struct BitNode{
	ElemType data;
	struct BitNode *lchild,*rchlid;
}BitNode,*Bitree;

void PreOrder(Bitree T){        //先序遍历（根左右） 
	if(T != NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchlid);
	}
} 

void InOrder(Bitree T){        //中序遍历（左根右） 
	if(T != NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchlid);
	}
} 

void PostOrder(Bitree T){        //后序遍历（左根右） 
	if(T != NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchlid);
		visit(T); 
	}
} 
