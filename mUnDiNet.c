/*以邻接矩阵为存储结构的无向网络
  实现遍历和用Prime方法产生最小生成树
*/
#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct node{
 	char vertexName[Max];//存放顶点名称
	double arc[Max][Max];//邻接矩阵，存储边的信息，有边用权值，无边用大数1E20
	int vertexNum,arcNum;//分别表示图中的顶点个数和边的条数
	int visited[Max];//顶点访问标志
}mUnDiNet;
void clear(mUnDiNet *p){//将图中的所有顶点访问标志清0
	int i;
	for(i=0;i<Max;i++)
		p->visited[i]=0;
}
mUnDiNet *createMUnDiNet(int n,int e){
	int i,j,k;
	double w;
	mUnDiNet *p=(mUnDiNet *)malloc(sizeof(mUnDiNet));
	p->vertexNum=n;
	p->arcNum=e;
	printf("请依次输入每个顶点的名称:\n");
	for(i=0;i<p->vertexNum;i++)
		scanf(" %c",&(p->vertexName[i]));
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++)
			p->arc[i][j]=1E20;//这个二重循环，是对邻接矩阵的元素初始化，所有元素值设置为10的20次方，很大的数 
	printf("请输入每条边所依附的两个顶点的下标及权值:\n");
	for(k=1;k<=e;k++){
		scanf("%d%d%lf",&i,&j,&w);
		p->arc[j][i]=p->arc[i][j]=w;
	}
	clear(p);//调用clear()函数，将所有顶点的访问标志设置为0
	return p;
}
void DFS(mUnDiNet *p,int i){//对于无向网络p,从下标为i的顶点开始进行深度优先遍历
	int j;
	printf("%c",p->vertexName[i]);//输出下标为i的顶点名称
	p->visited[i]=1;//将下标为i的顶点访问标志改为1
	for(j=0;j<p->vertexNum;j++)
		if(p->arc[i][j]<1E20&&p->visited[j]==0) DFS(p,j);
}
void BFS(mUnDiNet *p,int i){//对于无向网络p,从下标为i的顶点开始进行广度优先遍历
	int Q[Max];
	int front=-1,rear=-1;
	int v,j;
	Q[++rear]=i;
	p->visited[i]=1;
	while(front!=rear){
		v=Q[++front];
		printf("%c",p->vertexName[v]);
		for(j=0;j<p->vertexNum;j++)
			if(p->arc[j][v]<1E20&&p->visited[j]==0){
				Q[++rear]=j;
				p->visited[j]=1;
			}
	}
	printf("\n");
	clear(p);
}
void Prime(mUnDiNet *p,int v){ 
	int i,j,k,adjvex[Max];//变量定义和初始化
	double lowcost[Max];
	for(i=0;i<p->vertexNum;i++){//对adjvex[]和lowcost[]数组初始化
		adjvex[i]=v;    lowcost[i]=p->arc[v][i];
	}
	lowcost[v]=0; //将v加入到U中   
	//j=MinEdge(lowcost,vertexNum);
	for(k=1;k<p->vertexNum;k++){//k是计数器，控制循环次数，还有vertexNum个顶点需要加入到U中
        for(i=0;i<p->vertexNum;i++)//假设第1个值不为0的lowcost[i]为最小权值
			if(lowcost[i]) break;
		j=i;//j用于存储最小的lowcost[i]的下标
		for(i=j+1;i<p->vertexNum;i++)//找j之后的更小的lowcost[i]，将其下标i赋值给j
			if(lowcost[i]&&lowcost[i]<lowcost[j]) j=i;
		//cout<<'('<<j<<','<<adjvex[j]<<')'<<lowcost[j]<<"  ";
		printf("(%d,%d)%lf  ",j,adjvex[j],lowcost[j]);
		lowcost[j]=0;
		for(i=0;i<p->vertexNum;i++)/*调整数组shortEdge[n]*/
            if(p->arc[i][j]<lowcost[i]){
                lowcost[i]=p->arc[i][j]; 
				adjvex[i]=j;
			}
	}
	printf("\n");
}
void deleteMUnDiNet(mUnDiNet *p){	free(p); }
int main(){
	int n,e;
	printf("请输入顶点个数和边的条数:\n");
	scanf("%d%d",&n,&e);
	mUnDiNet *mudn=createMUnDiNet(n,e);
	printf("从顶点A开始进行深度优先遍历的序列为:\n");
	DFS(mudn,0);
	printf("\n");
	clear(mudn);
	printf("从顶点A开始进行广度优先遍历的序列为:\n");
    BFS(mudn,0);
	printf("用Prime方法，从顶点A开始产生最小生成树的过程如下：\n");
	Prime(mudn,0);
	deleteMUnDiNet(mudn);
	return 0;
}
