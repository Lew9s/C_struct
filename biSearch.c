//折半查找算法 
#include<stdio.h>
int biSearch(int r[],int low,int high,int key){//假设r[0]没有放元素,数组递增有序 
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(r[mid]==key) return mid;
		else if(key>r[mid]) low=mid+1;
		     else high=mid-1;
	}
	return 0;	 
}
//思考：如果r[]数组元素是递减有序，以上代码应该如何修改？
int biSearch2(int r[],int low,int high,int key){//假设r[0]没有放元素,数组递减有序 
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



 
