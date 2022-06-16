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
	int i,j,di;
}Box;
typedef struct{
	Box data[Max];
	int top;
}StType;
void InitMg(){
	printf("在迷宫的四面各添一堵墙，初始化用于存储迷宫的二维数组\n");
	/*printf("请按矩阵方式依次输入二维数组元素值：");
	int i,j;
	for(i=0;i<M+2;++i)
		for(j=0;j<N+2;++j)
			scanf("%d",&mg[i][j]);
	*/
}
int mgPath(int xi,int yi,int xe,int ye){
	int i,j,k,di,find;
	StType st;
	st.top=-1;
	st.top++;
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].di=-1;
	mg[xi][yi]=-1;
	while(st.top>-1){
		i=st.data[st.top].i;
		j=st.data[st.top].j;
		di=st.data[st.top].di;
		if(i==xe&&j==ye){
			printf("迷宫路径如下：\n");
			for(k=0;k<=st.top;k++){
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if((k+1)%5==0) printf("\n");
			}
			printf("\n");
			return 1; 
		}
		find=0;
		while(di<4&&find==0){
			di++;
			switch(di){
				case 0:i=st.data[st.top].i-1; j=st.data[st.top].j; break;
				case 1:i=st.data[st.top].i; j=st.data[st.top].j+1; break;
				case 2:i=st.data[st.top].i+1; j=st.data[st.top].j; break;
				case 3:i=st.data[st.top].i; j=st.data[st.top].j-1; 
			}
			if(mg[i][j]==0) find=1;
		}
		if(find==1){
			st.data[st.top].di=di;
			st.top++;
			st.data[st.top].i=i;
			st.data[st.top].j=j;
			st.data[st.top].di=-1;
			mg[i][j]=-1;
		}
		else{
			mg[st.data[st.top].i][st.data[st.top].j]=0;	
			st.top--;
		}
	}
	return 0;
}
int main(){
	InitMg();
	if(!mgPath(1,1,M,N)){
		printf("该迷宫问题没有解！\n");
	}
	return 0;
}

