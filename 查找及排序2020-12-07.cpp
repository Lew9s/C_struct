int seqSearch0(int r[],int n,int key){//假设原始数据存储在r[0]~r[n-1]中
	//在含有n个元素的数组r中查找其值与key相等的元素
	for(int i=0;i<n;++i)
		if(r[i]==key) return i+1;
	return 0;
}

int seqSearch1(int r[],int n,int key){//改进的顺序查找算法
	//在含有n个元素的数组r中查找其值与key相等的元素，假设原始数据存放在r[1]~r[n]中
	r[0]=key;
	int i=n;
	while(r[i]!=r[0]) --i;
	return i;
}

//折半（二分）查找，要求原始必须存储在数组中，且数据递增(减)有序
int biSearch(int r[],int low,int high,int key){
	//r[0]不存放元素，r[]数组元素递增有序，在下标low到high区间内查找值与key相等的元素
	while(low<=high){
		int mid=(low+high)/2;
		if(key==r[mid]) return mid;
		if(key<r[mid]) high=mid-1;
		else low=mid+1;
	}
	return 0;
}

/*散列表的构造，分别用线性探测法、拉链法解决冲突
1.数数元素个数n
2.计算表长m=n/填充因子
3.计算除数p,取不大于表长m的最大质数
4.散列地址公式：H(key)=key%p

*/
/*
排序 ：重点掌握：插入排序、交换排序、选择排序
       了解归并排序
	   插入排序：直接插入排序、希尔排序


*/

void insertSort0(int r[],int n){//原始的直接插入排序算法，假设原始数据存储在r[0]~r[n-1]中
    for(int i=1;i<n;++i){
		int j=i-1;
		int temp=r[i];
		while(temp<r[j]&&j>=0) r[j+1]=r[j--];
		r[j+1]=temp;
	}
}
void insertSort(int r[],int n){//改进的直接插入排序算法，假设原始数据存储在r[1]~r[n]中
	for(int i=2;i<=n;++i){
		r[0]=r[i];//r[0]称为哨所
		int j=i-1;
		while(r[0]<r[j]){  r[j+1]=r[j]; --j;  }
		r[j+1]=r[0];
	}

}
//回去预习希尔排序 、冒泡排序、快速排序

