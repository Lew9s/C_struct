#include<stdio.h>
typedef struct BitNode{      //二叉树结点（链式存储） 
	Elemtype data;
	struct BitNode *lchild,*rchild;
}BitNode, *Bitree;

typedef LinkNode{            //链式队列结点 
	BitNode * data;
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front,*rear;   //队头队尾 
}LinkQueue;

void LevelOrder(Bitree){
	LinkQueue Q;
	InitQueue(Q);                    //初始化辅助队列 
	Bitree p;
	EnQueue(Q,T);                    //将根结点入队 
	while(!IsEmpty(Q)){              //队列不空则循环 
		DeQueue(Q,p);                //队头结点出队 
		visit(p);                    //访问出队结点 
		if(p->lchild!=NULL)
		    EnQueue(Q,p->lchild);    //左孩子入队 
		if(p->rchild!=NULL)
		    EnQueue(Q,p->rchild);    //右孩子入队 
	}
}

/*算法思想：
1）初始化一个辅助队列
2）根结点入队
3）若队列非空，则队头结点出队，访问该结点，并将其左孩子和右孩子入队
4）重复3直至队列为空*/ 
