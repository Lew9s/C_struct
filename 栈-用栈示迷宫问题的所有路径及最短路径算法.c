//用栈求解迷宫问题的所有路径及最短路径算法代码 
#include<stdio.h>
#define M 4
#define N 4
#define Max 100
int mg[M+2][N+2]={{1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
	{1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1}};
	//一个迷宫，四周加上均为1的外框 
struct{
	int i,j;
	int di;
}St[Max],Path[Max];           //定义栈和存放最短路径的数组 
int top=-1;                   //栈顶指针 
int count=1;                  //路径计数器 
int minlen=Max;               //最短路径长度
void dispapath(){             //输出一条路径并求最短路径 
	int k;
	printf("%5d:",count++);    //输出第count条路径 
	for(k=0;k<=top;k++)
		printf("(%d,%d)",St[k].i,St[k].j); 
	printf("\n");
	if(top+1<minlen){            //比较找最短路径 
		for(k=0;k<=top;++k)
			Path[k]=St[k];       //将最短路径存放在Path中 
		minlen=top+1;            //将最短路径长度存放在minlen中 
	}
}
void dispminpath(){             //输出第1条最短路径 
	int k;
	printf("最短路径如下：\n"); 
	printf("长度:%d\n",minlen);
	printf("路径:");
	for(k=0;k<minlen;++k)
		printf("(%d,%d)",Path[k].i,Path[k].j);
	printf("\n");
}
void mgpath(int xi,int yi,int xe,int ye){  //求迷宫路径 
	int i,j,i1,j1,di;
	int find;
	top++;                             //进栈 
	St[top].i=xi;  	St[top].j=yi;
	St[top].di=-1;  mg[xi][yi]=-1;     //初始方块进栈
	while(top>-1){                     //栈非空时循环 
		i=St[top].i;  j=St[top].j; di=St[top].di;//取栈顶方块(i,j) 
		if(i==xe &&j==ye){               //找到了出口
			dispapath();                 //输出一条路径 
			mg[i][j]=0;                  //让出口变为其他路径可走方块
			top--;                        //出口退栈，即回退一个方块 
			i=St[top].i;  j=St[top].j; di=St[top].di;
			//让栈顶方块变为当前方块 
		}
		find=0;//找下一个可走方块(i1,j1)
		while(di<4&&!find){
			di++;
			switch(di){
				case 0:i1=i-1; j1=j; break;
				case 1:i1=i; j1=j+1; break;
				case 2:i1=i+1; j1=j; break;
				case 3:i1=i; j1=j-1;
			}
			if(mg[i1][j1]==0) find=1;
		} 
		if(find){                  //找到了下一个可走方块 
			St[top].di=di;         //修改原栈顶元素的di值 
			top++;	St[top].i=i1;   St[top].j=j1;
			St[top].di=-1;         //下一个可走方块(i1,j1)进栈
			mg[i1][j1]=-1;       //避免重复走到该方块 
		}
		else{                   //没有路径可走，则(i,j)方块退栈 
			mg[i][j]=0;         //让该位置变为其他路径可走方块 
			top--;
		}
	}
	dispminpath();	           //输出最短路径 
}

int main(){
	printf("迷宫所有路径如下：\n");
	mgpath(1,1,M,N);
	return 0;
}
