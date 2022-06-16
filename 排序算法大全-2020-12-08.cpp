/*排序算法大全-2020-12-08
   假设原始数据存储于r[1]~r[n]中，r[0]作为哨所
*/
#include<iostream.h>
void print(int r[],int n){//输出函数1,输出r[1]~r[n]
	for(int i=1;i<=n;i++)
		cout<<r[i]<<"  ";
	cout<<endl;
}
void print(int r[],int first,int end){//输出函数2,输出r[first]~r[end]
	for(int i=first;i<=end;i++)
		cout<<r[i]<<"  ";
	cout<<endl;
}
void insertSort(int r[],int n){//直接插入排序
	for(int i=2;i<=n;i++){
		r[0]=r[i];
		int j=i-1;
		while(r[0]<r[j]) r[j+1]=r[j--];
		r[j+1]=r[0];
	}
}
void shellSort(int r[],int n){//希尔排序
	for(int d=n/2;d>=1;d/=2)
		for(int i=d+1;i<=n;i++){
		   r[0]=r[i];
		   int j=i-d;
		   while(j>0&&r[0]<r[j]) {r[j+d]=r[j];j-=d;}
		   r[j+d]=r[0];
		}
}
void bubbleSort1(int r[],int n ){//冒泡排序1
	for(int i=1;i<n;i++){
		int noswap=1;
		for(int j=n;j>i;j--)
			if(r[j]<r[j-1]){
				r[0]=r[j];
				r[j]=r[j-1];
				r[j-1]=r[0];
				noswap=0;
			}
		if(noswap) break;
	}
}
void bubbleSort2(int r[],int n){//冒泡排序2
	int exchange=n;
	while(exchange){
		int bound=exchange;
		exchange=0;
		for(int j=1;j<bound;j++)
			if(r[j]>r[j+1]){
				r[0]=r[j];r[j]=r[j+1];r[j+1]=r[0];
				exchange=j;
			}
	}
}
int partition(int r[],int first,int end){//快速排序的分区算法，
	//对r数组从下标first到end之间的元素进行分区
	r[0]=r[first];
	int i=first,j=end;
	while(i<j){
		while(i<j&&r[j]>=r[0])j--;
		if(i<j) r[i++]=r[j];
		while(i<j&&r[i]<=r[0]) i++;
		if(i<j) r[j--]=r[i];
	}
	r[i]=r[0];//或r[j]=r[0];
	return i;//或return j;
}
void quickSort(int r[],int first,int end){//快速排序
	if(first<end){
		int position=partition(r,first,end);
		quickSort(r,first,position-1);
		quickSort(r,position+1,end);
	}
}
void selectSort(int r[],int n){//简单选择排序
	for(int i=1;i<n;i++){
		int minxb=i;
		for(int j=i+1;j<=n;j++)
			if(r[j]<r[minxb]) minxb=j;
		if(i!=minxb){
			r[0]=r[i];r[i]=r[minxb];r[minxb]=r[0];
		}
	}
}
//堆排序,堆（大根堆、小根堆），完全二叉树中，
//树及所有的子树，
//根结点的权值不小于左右孩子的权值
void sift(int r[],int k,int m){	//对r[]数组，从k到m之间进行堆调整
	int i=k,j=2*i;
	while(j<=m){
		if(j<m&&r[j]<r[j+1]) j++;
		if(r[i]>r[j]) break;
		else{
			r[0]=r[i];r[i]=r[j];r[j]=r[0];
			i=j;j=2*i;
		}
	}
}
void heapSort(int r[],int n){//堆排序
	for(int i=n/2;i>=1;i--)
		sift(r,i,n);
	//以上循环结束后，建成了初始的大根堆
	for(i=1;i<n;i++){
		r[0]=r[1];
		r[1]=r[n-i+1];
		r[n-i+1]=r[0];
		sift(r,1,n-i);
		cout<<"第"<<i<<"趟堆排序的结果：\n";
		for(int j=1;j<=n;j++)
			cout<<r[j]<<"  ";
		cout<<endl;
	}
}
/*void merge(int r[],int s,int m,int t){//一次归并算法
	int r1[20];
	int i=s,j=m+1,k=s;
	while(i<=m&&j<=t)
		if(r[i]<=r[j]) r1[k++]=r[i++];
		else r1[k++]=r[j++];
	while(i<=m) r1[k++]=r[i++];
	while(j<=t) r1[k++]=r[j++];
	for(i=s;i<=t;i++) r[i]=r1[i];
}
void mergePass(int r[],int n,int h){
	//一趟归并排序算法，从下标1开始存放待排序序列
	int i=1;
	while(i<=n-2*h+1){
		merge(r,i,i+h-1,i+2*h-1);
		i+=2*h;
	}
	if(i<=n-h+1) merge(r,i,i+h-1,n);
	else
		for(int k=i;k<=n;k++) r1[k]=r[k];

}

void mergeSort1(int r[],int n){
	//归并排序非递归算法,从下标1开始存放待排序序列
	int h=1;
	while(h<n){
		mergePass(r,n,h);
		h=2*h;*/
		/*mergePass(r1,r,n,h);//待排序序列从数组r1中传到r中
		h=2*h;
	}
}

void mergeSort2(int r[],int s,int t){
	if(s==t) return;
	else{
		int m=(s+t)/2;
		mergeSort2(r,s,m);
		mergeSort2(r,m+1,t);
		merge(r,s,m,t);
	}
}
*/

void main(){
	int a1[]={0,25,16,80,56,32,45,12,87,64};
	int b1[]={0,25,16,80,56,32,45,12,87,64};
	int c1[]={0,25,16,80,56,32,45,12,87,64};
	int c2[]={0,25,16,80,56,32,45,12,87,64};

	int d1[]={0,25,16,80,56,32,45,12,87,64};
	int e1[]={0,25,16,80,56,32,45,12,87,64};
	int f1[]={0,25,16,80,56,32,45,12,87,64};
	int g1[]={0,25,16,80,56,32,45,12,87,64};
	int h1[]={0,25,16,80,56,32,45,12,87,64};
	cout<<"排序前,a1数组元素：\n";
	print(a1,9);
	insertSort(a1,9);
	cout<<"直接插入排序后,a1数组元素：\n";
	print(a1,9);
	cout<<"排序前,b1数组元素：\n";
	print(b1,9);
	shellSort(b1,9);
	cout<<"希尔排序后,b1数组元素：\n";
	print(b1,9);
	
	cout<<"排序前,c1数组元素：\n";
	print(c1,9);
	bubbleSort1(c1,9);
	cout<<"冒泡排序法1排序后,c1数组元素：\n";
	print(c1,9);

	cout<<"排序前,c2数组元素：\n";
	print(c2,9);
	bubbleSort2(c2,9);
	cout<<"冒泡排序法2排序后,c2数组元素：\n";
	print(c2,9);

	cout<<"排序前,d1数组元素：\n";
	print(d1,1,9);
	quickSort(d1,1,9);
	cout<<"快速排序后,d1数组元素：\n";
	print(d1,1,9);
	
	cout<<"排序前,e1数组元素：\n";
	print(e1,9);
	selectSort(e1,9);
	cout<<"简单选择排序后,e1数组元素：\n";
	print(e1,9);
	
	cout<<"排序前,f1数组元素：\n";
	print(f1,9);
	heapSort(f1,9);
	cout<<"堆排序后,f1数组元素：\n";
	print(f1,9);
	
	/*cout<<"排序前,g1数组元素：\n";
	print(g1,9);
	//mergeSort1(g1,g,9);
	mergeSort2(g1,1,9);
	cout<<"归并排序(递归)后,g1数组元素：\n";
	print(g1,9);

	cout<<"排序前,h1数组元素：\n";
	print(h1,9);
	mergeSort1(h1,9);
	cout<<"归并排序(非前递归)后,h1数组元素：\n";
	print(h1,9);
	*/
}