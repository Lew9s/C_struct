/*�������������࣬ʵ����Kruskal����������С������*/
#include<iostream>
#include<cstdio>
using namespace std;
const int MaxVertexNum=10;//�����������
const int MaxArcNum=20;//�ߵ��������
struct arcNode{//����߽�����������
	int from,to;
	int weight;
};
template<typename T>
class unDiNetKruskal{
	int vertexNum,arcNum;
	T vertexName[MaxVertexNum];
	arcNode arc[MaxArcNum];
public:
/*	unDiNetKruskal(int n,int e){//���캯��
		vertexNum=n;  arcNum=e;
		int k;
		cout<<"��������ÿ���������ƣ�\n";
		for(k=0;k<vertexNum;k++)
			cin>>vertexName[k];
		cout<<"��Ȩֵ��С������������ÿ����������������������±꼰��Ӧ��Ȩֵ��\n";
		for(k=0;k<arcNum;k++)
			cin>>arc[k].from>>arc[k].to>>arc[k].weight;
	}
*/
    unDiNetKruskal(){
		freopen("i2.txt","r",stdin);//�����������ض���Ϊi1.txt�ļ�������
		int i,n,e,from,to;
		int w;
		scanf("%d%d",&n,&e);//nΪ��������eΪ�ߵ�����
		vertexNum=n;  arcNum=e;
		cout<<"���������"<<vertexNum<<"  �ߵ�������"<<arcNum<<endl;
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
	cout<<"�ÿ�³˹����������������С�����������У�\n";
	udnk.Kruskal();
}




