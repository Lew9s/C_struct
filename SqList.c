#include<stdio.h> 
typedef int ElemType;
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
SqList * Create(ElemType a[],int n){//����˳���
	SqList *L;//����ָ�����L
	int i;
	L=(SqList *)malloc(sizeof(SqList));
	for(i=0;i<n;i++)
		L->data[i]=a[i];
	L->length=n;
	return L;
}
SqList *IniList(){
	SqList *L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
	return L;	
}
int Length(SqList *L){
	return L->length;
}
int Empty(SqList *L){
	return (L->length==0?1:0);
}
int Get(SqList *L,int i,ElemType *x){//ȡL���е�iλ���ϵ�Ԫ��ֵ��������β�x��ָ��ı����� 
	if(L->length==0) {
		printf("�ձ��޷�ȡԪ��\n"); return 0;
	}
	if(i<1||i>L->length){
		printf("λ�ò������޷�ȡԪ��\n"); return 0;
	}
	*x=L->data[i-1]; 
	return 1; 
}
int Locate(SqList *L,ElemType x){
	int i;
	for(i=0;i<L->length;i++)
		if(L->data[i]==x) return i+1;
	return 0;
}
int Insert(SqList *L,int i,ElemType x){
	if(L->length>=MaxSize){
		printf("���������ܲ���\n");return 0;
	}
	if(i<1||i>L->length+1){
		printf("λ�ò��������ܲ���\n");return 0;
	}
	int j;
	for(j=L->length-1;j>=i-1;j--) 
		L->data[j+1]=L->data[j];
	L->data[i-1]=x;
	L->length++;
	return 1;
}
/*int Delete(SqList *L,int i,ElemType *x){
	....; 
}*/
void printList(SqList *L){//�������L���е�ÿ��Ԫ��ֵ
	int i;
	for(i=0;i<L->length;++i)
		printf("%4d",L->data[i]);
	printf("\n");
}

int main(){
	SqList *L,*L1;
	ElemType a[]={10,15,5,20,25};
	L=Create(a,5);
	printList(L);
	L1=IniList();
	printf("%d\n",L1->length);
	printf("%d\n",Length(L));
	printf("%d\n",Empty(L1));
	printf("%d\n",Empty(L));
	ElemType m;
	int k=Get(L,2,&m);//int k=Get(L,6,&m);
	printf("%d,%d\n",k,m);
	printf("%d\n",Locate(L,75));//printf("%d\n",Locate(L,5));
	printf("%d\n",Insert(L,3,100));
	printList(L);
	//����ɾ������ 
	//.... 
	return 0;
}
