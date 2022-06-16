//迷宫算法-队列存储
#include<stdio.h>
#define Max 100
#define M 8
#define N 8
//int mg[M+2][N+2];
int mg[M+2][N+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},{1,0,1,1,1,0,0,0,0,1},
{1,0,0,0,1,0,0,0,0,1},{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
typedef struct{
	int i,j,pre;
}Box;
typedef struct{
	Box data[Max];
	int front,rear;
}QuType;
typedef struct{
	int index,i,j,pre;
}Box2;
void print(QuType sq,int front){
	if(front!=-1){
		print(sq,sq.data[front].pre);
		printf("(%d,%d)\n",sq.data[front].i,sq.data[front].j);
	}
}
void print2(QuType sq,int front){
	//Box2 Index[Max],k=0,i;
	Box2 Index[Max];
	int k=0,i;
	Index[k].index=front;
	Index[k].i=sq.data[front].i;
	Index[k].j=sq.data[front].j;
	Index[k].pre=sq.data[front].pre;
	k++;
	while(Index[k-1].pre!=-1){
		Index[k].index=Index[k-1].pre;
		Index[k].i=sq.data[Index[k].index].i;
		Index[k].j=sq.data[Index[k].index].j;
		Index[k].pre=sq.data[Index[k].index].pre;
		k++;
	}
	printf("迷宫路径如下:\n");
	for(i=0;i<k;++i){
		printf("\t(%d,%d)",Index[k-1-i].i,Index[k-1-i].j);
		if((i+1)%5==0)  printf("\n");
	}
	printf("\n");
}
void InitMg(){
	printf("在迷宫的四面各添一堵墙，初始化用于存储迷宫的二维数组\n");
	/*printf("请按矩阵方式依次输入二维数组元素值：");
	int i,j;
	for(i=0;i<M+2;++i)
		for(j=0;j<N+2;++j)
			scanf("%d",&mg[i][j]);
	*/
	
}	
int mgPath2(int xi,int yi,int xe,int ye){
	//搜索路径(xi,yi)->(xe,ye)
	int i,j,find=0,di; 
	QuType qu;//定义顺序队列
	qu.front=qu.rear=-1;
	qu.rear++;
	qu.data[qu.rear].i=xi;
	qu.data[qu.rear].j=yi;
	qu.data[qu.rear].pre=-1;
	mg[xi][yi]=-1;
	while(qu.front!=qu.rear){
		qu.front++;
		i=qu.data[qu.front].i;
		j=qu.data[qu.front].j;
		if(i==xe&&j==ye){
			find=1;
			//print(qu,qu.front);
			print2(qu,qu.front);
			return 1; 
		}
		for(di=0;di<4;++di){
			switch(di){
				case 0:i=qu.data[qu.front].i-1;
					   j=qu.data[qu.front].j;
					   break;
				case 1:i=qu.data[qu.front].i;
					   j=qu.data[qu.front].j+1;
					   break;
				case 2:i=qu.data[qu.front].i+1;
					   j=qu.data[qu.front].j;
					   break;
				case 3:i=qu.data[qu.front].i;
					   j=qu.data[qu.front].j-1;
			}
			if(mg[i][j]==0){
				qu.rear++;
				qu.data[qu.rear].i=i;
				qu.data[qu.rear].j=j;
				qu.data[qu.rear].pre=qu.front;
				mg[i][j]=-1;
			}
		}
	} 
	return 0; 
}
int main(){
	InitMg();
	if(!mgPath2(1,1,M,N)){
		printf("该迷宫问题没有解！\n");
	}
	return 0;
}
