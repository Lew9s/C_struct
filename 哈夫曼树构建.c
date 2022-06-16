#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	float weight;
	int parent,lchild,rchild;
}hufftree;

hufftree* CreateHufftree(int n){     //构造哈夫曼树 
	hufftree* ht;
	ht=(hufftree*)malloc(sizeof(hufftree)*(2*n-1));
	int i=0 ,i1,i2,k=0;
	for(i=0;i<2*n-1;i++){
		ht[i].rchild=ht[i].parent=ht[i].lchild=-1;//初始化 
	}
	printf("依次输入叶子结点的权值： \n");
	for(k=0;k<n;k++){
		sacnf("%f",&ht[k].weight);
	}
	while(k<2*n-1){              //18行结束时k为n+1,k之前的结点都是带权结点 
		i1=0;                    //i1为第一次找出的最小权值的下标 
		while(i1<k){
			if(ht[i1].parent==-1)
			    break;
		    i1++;               //i1对应的结点未使用则绑定否则向后找 
		}
		i=i1+1;
		while(i<k){
			if(ht[i].parent==-1 && ht[i].weight<ht[i1].weight)
			i1=i;               //保证i1为最小权值的下标 
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

void Deletehufftree(hufftree* ht){    //销毁哈夫曼树 
	free(ht);
}

void Printhufftree(hufftree* ht,int n){   //打印哈夫曼树 
	printf("结点下标  结点权值  双亲下标  左孩子下标  右孩子下标\n");
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

