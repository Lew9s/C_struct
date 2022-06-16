/*定义无向网络类，实现用Kruskal方法产生最小生成树*/
#include<iostream>
#include<cstdio>
using namespace std;
const int MaxVertexNum=10;//顶点的最多个数
const int MaxArcNum=20;//边的最多条数
struct arcNode{//定义边结点的数据类型
	int from,to;
	int weight;
};
template<typename T>
class unDiNetKruskal{
	int vertexNum,arcNum;
	T vertexName[MaxVertexNum];
	arcNode arc[MaxArcNum];
public:
/*	unDiNetKruskal(int n,int e){//构造函数
		vertexNum=n;  arcNum=e;
		int k;
		cout<<"依次输入每个顶点名称：\n";
		for(k=0;k<vertexNum;k++)
			cin>>vertexName[k];
		cout<<"按权值由小到大依次输入每条边所依附的两个顶点的下标及相应的权值：\n";
		for(k=0;k<arcNum;k++)
			cin>>arc[k].from>>arc[k].to>>arc[k].weight;
	}
*/
    unDiNetKruskal(){
		freopen("i2.txt","r",stdin);//键盘输入流重定向为i1.txt文件输入流
		int i,n,e,from,to;
		int w;
		scanf("%d%d",&n,&e);//n为顶点数，e为边的条数
		vertexNum=n;  arcNum=e;
		cout<<"顶点个数："<<vertexNum<<"  边的条数："<<arcNum<<endl;
		for(i=0;i<vertexNum;i++){
			vertexName[i]=(char)('0'+i);
		}
		for(i=0;i<arcNum;i++){
			scanf("%d%d%d",&from,&to,&w);
			arc[i].from=from;
			arc[i].to=to;
			arc[i].weight=w;
			cout<<arc[i].from<<'\t'<<arc[i].to<<'\t'<<arc[i].weight<<endl;
		}
	}

/*	int findRoot(int parent[],int v){
		int t=v;
		while(parent[t]>-1) t=parent[t];
		return t;
	}
	void Kruskal(){
		int parent[MaxVertexNum];
		int i,vex1,vex2,num=0;
		for(i=0;i<vertexNum;i++)
			parent[i]=-1;
		for(i=0;i<arcNum;i++){
			vex1=findRoot(parent,arc[i].from);
			vex2=findRoot(parent,arc[i].to);
			if(vex1!=vex2){
				cout<<'('<<arc[i].from<<','<<arc[i].to<<')'<<arc[i].weight<<endl;
				parent[vex2]=vex1;
				num++;
				if(num==vertexNum-1) return;
			}
		}
	}
	*/
	int findRoot(int parent[],int v){
	int t=v;
	while(parent[t]>-1) t=parent[t];
	return t;
}
void Kruskal(){
	int parent[MaxVertexNum];
	int i,vex1,vex2,num=0;
	for(i=0;i<vertexNum;i++) parent[i]=-1;
	for(i=0;i<arcNum;i++){
		vex1=findRoot(parent,arc[i].from);
		vex2=findRoot(parent,arc[i].to);
		if(vex1!=vex2){
			parent[vex2]=vex1;
			cout<<'('<<vertexName[arc[i].from]<<','<<vertexName[arc[i].to]<<')'<<arc[i].weight<<"  ";
			num++;
			if(num==vertexNum-1) {  cout<<endl;   return;}
		}
	}
}
};
void main(){
	//unDiNetKruskal <char> udnk(6,9);
	unDiNetKruskal <char> udnk;
	cout<<"用克鲁斯卡尔方法产生的最小生成树的序列：\n";
	udnk.Kruskal();
}




