#include<stdio.h>
typedef struct BitNode{      //��������㣨��ʽ�洢�� 
	Elemtype data;
	struct BitNode *lchild,*rchild;
}BitNode, *Bitree;

typedef LinkNode{            //��ʽ���н�� 
	BitNode * data;
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front,*rear;   //��ͷ��β 
}LinkQueue;

void LevelOrder(Bitree){
	LinkQueue Q;
	InitQueue(Q);                    //��ʼ���������� 
	Bitree p;
	EnQueue(Q,T);                    //���������� 
	while(!IsEmpty(Q)){              //���в�����ѭ�� 
		DeQueue(Q,p);                //��ͷ������ 
		visit(p);                    //���ʳ��ӽ�� 
		if(p->lchild!=NULL)
		    EnQueue(Q,p->lchild);    //������� 
		if(p->rchild!=NULL)
		    EnQueue(Q,p->rchild);    //�Һ������ 
	}
}

/*�㷨˼�룺
1����ʼ��һ����������
2����������
3�������зǿգ����ͷ�����ӣ����ʸý�㣬���������Ӻ��Һ������
4���ظ�3ֱ������Ϊ��*/ 
