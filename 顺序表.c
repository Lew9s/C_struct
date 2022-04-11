#include<stdio.h>
//顺序表静态分配
#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];       
	int length;
}SQList;

void InitList(SQList &L){        //初始化
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
	for(j=L.length;j>=i;j--)   //将第i个元素以后的元素后移 
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;            //在位置i处放入 
	L.length++;
	return true;
}

bool ListDelete(SQList &L,int i,int &e){
	if(i<1||i>L.length)
	    return false;
	e=L.data[i-1];
	int j;
	for(j=i;j<L.length;j++)   //将第i个位置后的元素前移 
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



//顺序表动态分配 
#include <stdlib.h>
#define InitSize 10    //默认的最大长度 
typedef struct{
	int *data;         //指示动态分配数组的指针
	int MaxSize;       //顺序表的最大容量 
	int length;        //顺序表的当前长度 
}SeqList; 

void InitList(SeqList &L){       //初始化 
	//用malloc函数申请一片连续的存储空间
	L.data=(int*)malloc(sizeof(int)*InitSize);
	L.MaxSize=InitSize;
	L.length=0; 
}

void IncreaseSize(SeqList &L,int len)  //增加动态数组长度 
{
	int i;
	int *p=L.data;
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));  //开辟新区域 
	for(i=0;i<L.length;i++)                            //复制数据 
	{
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;                           //修改最大长度 
	free(p);
}

int main(){
	SeqList L;
	InitList(L);
	IncreaseSize(L,5);
	return 0;
} 
