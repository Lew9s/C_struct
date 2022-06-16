//邻接表为存储结构的无向图 
#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct edNode{
	int adj;
	struct edNode *next;
}edgeNode;
typedef struct verNode{
	char vName;
	edgeNode * firstEdge;
}vertexNode; 
typedef struct node{
	int vertexNum,edgeNum;
	vertexNode data[Max];
	int visited[Max];
}adjGraph;
void clear(adjGraph *adjG){
	int i;
	for(i=0;i<Max;++i)	adjG->visited[i]=0;
}
adjGraph * createAdjGraph(int vNum,int eNum){
	adjGraph * p=(adjGraph *)malloc(sizeof(adjGraph));
	p->vertexNum=vNum;
	p->edgeNum=eNum;
	int i,j,k;
	edgeNode *s;
	printf("依次输入每个顶点的名称:\n");
	for(i=0;i<p->vertexNum;++i){
		scanf(" %c",&(p->data[i].vName));
		p->data[i].firstEdge=NULL;
	}
	printf("请依次输入每条边所依附的两全顶点的下标:\n");
	for(k=1;k<=p->edgeNum;++k){
		scanf("%d%d",&i,&j);
		s=(edgeNode *)malloc(sizeof(edgeNode));
		s->adj=j;
		s->next=p->data[i].firstEdge;
		p->data[i].firstEdge=s;
		s=(edgeNode *)malloc(sizeof(edgeNode));
		s->adj=i;
		s->next=p->data[j].firstEdge;
		p->data[j].firstEdge=s;	
	}
	clear(p);
	return p;
}
void DFS(adjGraph *adjG,int i){
	printf("%3c",adjG->data[i].vName);
	adjG->visited[i]=1;
	edgeNode *p=adjG->data[i].firstEdge;
	while(p){
		if(adjG->visited[p->adj]==0)
			DFS(adjG,p->adj);
		p=p->next;
	} 
}
void BFS(adjGraph *adjG,int i){
	int Q[Max];
	int front=-1,rear=-1;
	int v;
	edgeNode *p;
	Q[++rear]=i;
	adjG->visited[i]=1;
	while(front!=rear){
		v=Q[++front];
		printf("%3c",adjG->data[v].vName);
		p=adjG->data[v].firstEdge;
		while(p){
			if(adjG->visited[p->adj]==0){
				Q[++rear]=p->adj;
				adjG->visited[p->adj]=1;	
			}
			p=p->next;
		}
	}
	printf("\n");	
}
void deleteAdjGraph(adjGraph * adjG){
	int i;
	edgeNode *p;
	for(i=0;i<adjG->vertexNum;++i){
		p=adjG->data[i].firstEdge;
		while(p){
			adjG->data[i].firstEdge=adjG->data[i].firstEdge->next;
			free(p);
			p=adjG->data[i].firstEdge;
		}
	}
}
int main(){
	int ddgs,bts;
	printf("请输入顶点个数和边的条数:\n");
	scanf("%d%d",&ddgs,&bts);
	adjGraph *adjG=createAdjGraph(ddgs,bts);
	printf("从顶点A开始，进行深度优先遍历，序列：\n");
	DFS(adjG,0);
	printf("\n");
	clear(adjG);
	printf("从顶点A开始，进行广度优先遍历，序列：\n");
	BFS(adjG,0);
	clear(adjG);
	deleteAdjGraph(adjG);
	return 0;
}
