int seqSearch0(int r[],int n,int key){//����ԭʼ���ݴ洢��r[0]~r[n-1]��
	//�ں���n��Ԫ�ص�����r�в�����ֵ��key��ȵ�Ԫ��
	for(int i=0;i<n;++i)
		if(r[i]==key) return i+1;
	return 0;
}

int seqSearch1(int r[],int n,int key){//�Ľ���˳������㷨
	//�ں���n��Ԫ�ص�����r�в�����ֵ��key��ȵ�Ԫ�أ�����ԭʼ���ݴ����r[1]~r[n]��
	r[0]=key;
	int i=n;
	while(r[i]!=r[0]) --i;
	return i;
}

//�۰루���֣����ң�Ҫ��ԭʼ����洢�������У������ݵ���(��)����
int biSearch(int r[],int low,int high,int key){
	//r[0]�����Ԫ�أ�r[]����Ԫ�ص����������±�low��high�����ڲ���ֵ��key��ȵ�Ԫ��
	while(low<=high){
		int mid=(low+high)/2;
		if(key==r[mid]) return mid;
		if(key<r[mid]) high=mid-1;
		else low=mid+1;
	}
	return 0;
}

/*ɢ�б�Ĺ��죬�ֱ�������̽�ⷨ�������������ͻ
1.����Ԫ�ظ���n
2.�����m=n/�������
3.�������p,ȡ�����ڱ�m���������
4.ɢ�е�ַ��ʽ��H(key)=key%p

*/
/*
���� ���ص����գ��������򡢽�������ѡ������
       �˽�鲢����
	   ��������ֱ�Ӳ�������ϣ������


*/

void insertSort0(int r[],int n){//ԭʼ��ֱ�Ӳ��������㷨������ԭʼ���ݴ洢��r[0]~r[n-1]��
    for(int i=1;i<n;++i){
		int j=i-1;
		int temp=r[i];
		while(temp<r[j]&&j>=0) r[j+1]=r[j--];
		r[j+1]=temp;
	}
}
void insertSort(int r[],int n){//�Ľ���ֱ�Ӳ��������㷨������ԭʼ���ݴ洢��r[1]~r[n]��
	for(int i=2;i<=n;++i){
		r[0]=r[i];//r[0]��Ϊ����
		int j=i-1;
		while(r[0]<r[j]){  r[j+1]=r[j]; --j;  }
		r[j+1]=r[0];
	}

}
//��ȥԤϰϣ������ ��ð�����򡢿�������

