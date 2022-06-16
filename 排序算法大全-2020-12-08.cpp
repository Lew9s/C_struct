/*�����㷨��ȫ-2020-12-08
   ����ԭʼ���ݴ洢��r[1]~r[n]�У�r[0]��Ϊ����
*/
#include<iostream.h>
void print(int r[],int n){//�������1,���r[1]~r[n]
	for(int i=1;i<=n;i++)
		cout<<r[i]<<"  ";
	cout<<endl;
}
void print(int r[],int first,int end){//�������2,���r[first]~r[end]
	for(int i=first;i<=end;i++)
		cout<<r[i]<<"  ";
	cout<<endl;
}
void insertSort(int r[],int n){//ֱ�Ӳ�������
	for(int i=2;i<=n;i++){
		r[0]=r[i];
		int j=i-1;
		while(r[0]<r[j]) r[j+1]=r[j--];
		r[j+1]=r[0];
	}
}
void shellSort(int r[],int n){//ϣ������
	for(int d=n/2;d>=1;d/=2)
		for(int i=d+1;i<=n;i++){
		   r[0]=r[i];
		   int j=i-d;
		   while(j>0&&r[0]<r[j]) {r[j+d]=r[j];j-=d;}
		   r[j+d]=r[0];
		}
}
void bubbleSort1(int r[],int n ){//ð������1
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
void bubbleSort2(int r[],int n){//ð������2
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
int partition(int r[],int first,int end){//��������ķ����㷨��
	//��r������±�first��end֮���Ԫ�ؽ��з���
	r[0]=r[first];
	int i=first,j=end;
	while(i<j){
		while(i<j&&r[j]>=r[0])j--;
		if(i<j) r[i++]=r[j];
		while(i<j&&r[i]<=r[0]) i++;
		if(i<j) r[j--]=r[i];
	}
	r[i]=r[0];//��r[j]=r[0];
	return i;//��return j;
}
void quickSort(int r[],int first,int end){//��������
	if(first<end){
		int position=partition(r,first,end);
		quickSort(r,first,position-1);
		quickSort(r,position+1,end);
	}
}
void selectSort(int r[],int n){//��ѡ������
	for(int i=1;i<n;i++){
		int minxb=i;
		for(int j=i+1;j<=n;j++)
			if(r[j]<r[minxb]) minxb=j;
		if(i!=minxb){
			r[0]=r[i];r[i]=r[minxb];r[minxb]=r[0];
		}
	}
}
//������,�ѣ�����ѡ�С���ѣ�����ȫ�������У�
//�������е�������
//������Ȩֵ��С�����Һ��ӵ�Ȩֵ
void sift(int r[],int k,int m){	//��r[]���飬��k��m֮����жѵ���
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
void heapSort(int r[],int n){//������
	for(int i=n/2;i>=1;i--)
		sift(r,i,n);
	//����ѭ�������󣬽����˳�ʼ�Ĵ����
	for(i=1;i<n;i++){
		r[0]=r[1];
		r[1]=r[n-i+1];
		r[n-i+1]=r[0];
		sift(r,1,n-i);
		cout<<"��"<<i<<"�˶�����Ľ����\n";
		for(int j=1;j<=n;j++)
			cout<<r[j]<<"  ";
		cout<<endl;
	}
}
/*void merge(int r[],int s,int m,int t){//һ�ι鲢�㷨
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
	//һ�˹鲢�����㷨�����±�1��ʼ��Ŵ���������
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
	//�鲢����ǵݹ��㷨,���±�1��ʼ��Ŵ���������
	int h=1;
	while(h<n){
		mergePass(r,n,h);
		h=2*h;*/
		/*mergePass(r1,r,n,h);//���������д�����r1�д���r��
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
	cout<<"����ǰ,a1����Ԫ�أ�\n";
	print(a1,9);
	insertSort(a1,9);
	cout<<"ֱ�Ӳ��������,a1����Ԫ�أ�\n";
	print(a1,9);
	cout<<"����ǰ,b1����Ԫ�أ�\n";
	print(b1,9);
	shellSort(b1,9);
	cout<<"ϣ�������,b1����Ԫ�أ�\n";
	print(b1,9);
	
	cout<<"����ǰ,c1����Ԫ�أ�\n";
	print(c1,9);
	bubbleSort1(c1,9);
	cout<<"ð������1�����,c1����Ԫ�أ�\n";
	print(c1,9);

	cout<<"����ǰ,c2����Ԫ�أ�\n";
	print(c2,9);
	bubbleSort2(c2,9);
	cout<<"ð������2�����,c2����Ԫ�أ�\n";
	print(c2,9);

	cout<<"����ǰ,d1����Ԫ�أ�\n";
	print(d1,1,9);
	quickSort(d1,1,9);
	cout<<"���������,d1����Ԫ�أ�\n";
	print(d1,1,9);
	
	cout<<"����ǰ,e1����Ԫ�أ�\n";
	print(e1,9);
	selectSort(e1,9);
	cout<<"��ѡ�������,e1����Ԫ�أ�\n";
	print(e1,9);
	
	cout<<"����ǰ,f1����Ԫ�أ�\n";
	print(f1,9);
	heapSort(f1,9);
	cout<<"�������,f1����Ԫ�أ�\n";
	print(f1,9);
	
	/*cout<<"����ǰ,g1����Ԫ�أ�\n";
	print(g1,9);
	//mergeSort1(g1,g,9);
	mergeSort2(g1,1,9);
	cout<<"�鲢����(�ݹ�)��,g1����Ԫ�أ�\n";
	print(g1,9);

	cout<<"����ǰ,h1����Ԫ�أ�\n";
	print(h1,9);
	mergeSort1(h1,9);
	cout<<"�鲢����(��ǰ�ݹ�)��,h1����Ԫ�أ�\n";
	print(h1,9);
	*/
}