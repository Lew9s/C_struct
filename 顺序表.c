#include<stdio.h>
//˳���̬����
#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];       
	int length;
}SQList;

void InitList(SQList &L){        //��ʼ��
	int i=0;
	for(i=0;i<MaxSize;i++)
	{
		L.data[i]=0;
	}
	L.length=0;
}

bool ListInsert(SQList &L,int i,int e){
	if(i<1||i>L.length+1)
	    return false;
	if(L.length>=MaxSize)
	    return false;
    int j;
	for(j=L.length;j>=i;j--)   //����i��Ԫ���Ժ��Ԫ�غ��� 
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;            //��λ��i������ 
	L.length++;
	return true;
}

bool ListDelete(SQList &L,int i,int &e){
	if(i<1||i>L.length)
	    return false;
	e=L.data[i-1];
	int j;
	for(j=i;j<L.length;j++)   //����i��λ�ú��Ԫ��ǰ�� 
	    L.data[j-1]=L.data[j];
	L.length--;
	return true;
}

int main(){
	int e;
	SQList L;
	InitList(L);
	ListInsert(L,3,3);
	ListDelete(L,3,e);
	return 0;
}



//˳���̬���� 
#include <stdlib.h>
#define InitSize 10    //Ĭ�ϵ���󳤶� 
typedef struct{
	int *data;         //ָʾ��̬���������ָ��
	int MaxSize;       //˳����������� 
	int length;        //˳���ĵ�ǰ���� 
}SeqList; 

void InitList(SeqList &L){       //��ʼ�� 
	//��malloc��������һƬ�����Ĵ洢�ռ�
	L.data=(int*)malloc(sizeof(int)*InitSize);
	L.MaxSize=InitSize;
	L.length=0; 
}

void IncreaseSize(SeqList &L,int len)  //���Ӷ�̬���鳤�� 
{
	int i;
	int *p=L.data;
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));  //���������� 
	for(i=0;i<L.length;i++)                            //�������� 
	{
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;                           //�޸���󳤶� 
	free(p);
}

int main(){
	SeqList L;
	InitList(L);
	IncreaseSize(L,5);
	return 0;
} 
