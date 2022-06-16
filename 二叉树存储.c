#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef  int ElemType;
typedef struct TreeNode{    //顺序存储 
	ElemType value;         //结点中的数据元素 
	int isEmpty;            //结点是否为空 
}TreeNode; 

typedef struct BiTNode{      //链式存储 
	ElemType data;
	struct BiTNode *lchild,*rchild;    
}BiTNode,*BiTree;

int main(){
	//顺序存储 
	/*TreeNode t[MaxSize];
	int i=0;
	for(i=0;i<MaxSize; i++){
		t[i].isEmpty=1;
	} */
	
	//链式存储 
	BiTree root = NULL;     //定义空树 
	//插入根结点 
	root=(BiTree)malloc(sizeof(BiTNode));
	root->data=1;
	root->lchild=NULL;
	root->rchild=NULL;
	return 0; 
}

