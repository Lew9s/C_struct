#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef  int ElemType;
typedef struct TreeNode{    //˳��洢 
	ElemType value;         //����е�����Ԫ�� 
	int isEmpty;            //����Ƿ�Ϊ�� 
}TreeNode; 

typedef struct BiTNode{      //��ʽ�洢 
	ElemType data;
	struct BiTNode *lchild,*rchild;    
}BiTNode,*BiTree;

int main(){
	//˳��洢 
	/*TreeNode t[MaxSize];
	int i=0;
	for(i=0;i<MaxSize; i++){
		t[i].isEmpty=1;
	} */
	
	//��ʽ�洢 
	BiTree root = NULL;     //������� 
	//�������� 
	root=(BiTree)malloc(sizeof(BiTNode));
	root->data=1;
	root->lchild=NULL;
	root->rchild=NULL;
	return 0; 
}

