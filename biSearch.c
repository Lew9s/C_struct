//�۰�����㷨 
#include<stdio.h>
int biSearch(int r[],int low,int high,int key){//����r[0]û�з�Ԫ��,����������� 
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(r[mid]==key) return mid;
		else if(key>r[mid]) low=mid+1;
		     else high=mid-1;
	}
	return 0;	 
}
//˼�������r[]����Ԫ���ǵݼ��������ϴ���Ӧ������޸ģ�
int biSearch2(int r[],int low,int high,int key){//����r[0]û�з�Ԫ��,����ݼ����� 
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(r[mid]==key) return mid;
		else if(key<r[mid]) low=mid+1;
		     else high=mid-1;
	}
	return 0;	 
}
int main(){
	int a[9]={0,10,20,30,40,50,60,70,80};
	printf("%d\n",biSearch(a,4,7,50));//5
	printf("%d\n",biSearch(a,4,7,55));//0
	printf("%d\n",biSearch(a,4,7,80));//0
	printf("%d\n",biSearch(a,1,8,20));//2
	printf("%d\n",biSearch(a,1,8,25));//0
	int b[9]={0,80,70,60,50,40,30,20,10};
	printf("%d\n",biSearch2(b,4,7,50));//4
	printf("%d\n",biSearch2(b,4,7,55));//0
	printf("%d\n",biSearch2(b,4,7,80));//0
	printf("%d\n",biSearch2(b,1,8,20));//7
	printf("%d\n",biSearch2(b,1,8,25));//0
	return 0; 
}



 
