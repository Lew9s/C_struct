#include<stdio.h>
InsertSort(int r[],int n){//r[1]~r[n]�д����ԭʼ���ݣ�
	int i,j;
	i=2;
	while(i<=n){
		j=i-1;
		r[0]=r[i];
		while(j>0&&r[0]<r[j]) {
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=r[0];
		++i;
	} 
}
void Print(int r[],int n){
	int i;
	for(i=1;i<=n;++i)
		printf("%4d",r[i]);
	printf("\n");
}
int main(){
	int a[10]={0,15,8,12,6,20,10,18,14,28};
	printf("����ǰ������Ԫ��ֵ����Ϊ:\n");
	Print(a,9);
	InsertSort(a,9);
	printf("��ֱ�Ӳ��뷨���������Ԫ��ֵ����Ϊ:\n");
	Print(a,9);
	return 0; 
}
