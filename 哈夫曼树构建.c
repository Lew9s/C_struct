#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	float weight;
	int parent,lchild,rchild;
}hufftree;

hufftree* CreateHufftree(int n){     //����������� 
	hufftree* ht;
	ht=(hufftree*)malloc(sizeof(hufftree)*(2*n-1));
	int i=0 ,i1,i2,k=0;
	for(i=0;i<2*n-1;i++){
		ht[i].rchild=ht[i].parent=ht[i].lchild=-1;//��ʼ�� 
	}
	printf("��������Ҷ�ӽ���Ȩֵ�� \n");
	for(k=0;k<n;k++){
		sacnf("%f",&ht[k].weight);
	}
	while(k<2*n-1){              //18�н���ʱkΪn+1,k֮ǰ�Ľ�㶼�Ǵ�Ȩ��� 
		i1=0;                    //i1Ϊ��һ���ҳ�����СȨֵ���±� 
		while(i1<k){
			if(ht[i1].parent==-1)
			    break;
		    i1++;               //i1��Ӧ�Ľ��δʹ����󶨷�������� 
		}
		i=i1+1;
		while(i<k){
			if(ht[i].parent==-1 && ht[i].weight<ht[i1].weight)
			i1=i;               //��֤i1Ϊ��СȨֵ���±� 
		i++;
		}
		i2=0;
		while(i2<k){
			if(ht[i2].parent==-1 && i2!=i1)
			    break;
		    i2++;
		}
		i=i2+1;
		while(i<k){
			if(ht[i].parent==-1 && ht[i].weight<ht[i2].weight)
			    i2=i;
		    i++;
		}
		ht[k].weight=ht[i1].weight+ht[i2].weight;
		ht[k].lchild=i1;
		ht[k].rchild=i2;
		ht[i1].parent=ht[i2].parent=k;
		k++;
	}
	return ht;
}

void Deletehufftree(hufftree* ht){    //���ٹ������� 
	free(ht);
}

void Printhufftree(hufftree* ht,int n){   //��ӡ�������� 
	printf("����±�  ���Ȩֵ  ˫���±�  �����±�  �Һ����±�\n");
    int i;
    for(i=0;i<2*n-1;++i)
        printf("%-10d%-10f%-10d%-12d%-12d\n",i,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
}

int main(){
    hufftree *ht = CreateHufftree(6);
    Printhufftree(ht,6);
    Deletehufftree(ht);
    return 0;
}

