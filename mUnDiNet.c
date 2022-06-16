/*���ڽӾ���Ϊ�洢�ṹ����������
  ʵ�ֱ�������Prime����������С������
*/
#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct node{
 	char vertexName[Max];//��Ŷ�������
	double arc[Max][Max];//�ڽӾ��󣬴洢�ߵ���Ϣ���б���Ȩֵ���ޱ��ô���1E20
	int vertexNum,arcNum;//�ֱ��ʾͼ�еĶ�������ͱߵ�����
	int visited[Max];//������ʱ�־
}mUnDiNet;
void clear(mUnDiNet *p){//��ͼ�е����ж�����ʱ�־��0
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
	printf("����������ÿ�����������:\n");
	for(i=0;i<p->vertexNum;i++)
		scanf(" %c",&(p->vertexName[i]));
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++)
			p->arc[i][j]=1E20;//�������ѭ�����Ƕ��ڽӾ����Ԫ�س�ʼ��������Ԫ��ֵ����Ϊ10��20�η����ܴ���� 
	printf("������ÿ����������������������±꼰Ȩֵ:\n");
	for(k=1;k<=e;k++){
		scanf("%d%d%lf",&i,&j,&w);
		p->arc[j][i]=p->arc[i][j]=w;
	}
	clear(p);//����clear()�����������ж���ķ��ʱ�־����Ϊ0
	return p;
}
void DFS(mUnDiNet *p,int i){//������������p,���±�Ϊi�Ķ��㿪ʼ����������ȱ���
	int j;
	printf("%c",p->vertexName[i]);//����±�Ϊi�Ķ�������
	p->visited[i]=1;//���±�Ϊi�Ķ�����ʱ�־��Ϊ1
	for(j=0;j<p->vertexNum;j++)
		if(p->arc[i][j]<1E20&&p->visited[j]==0) DFS(p,j);
}
void BFS(mUnDiNet *p,int i){//������������p,���±�Ϊi�Ķ��㿪ʼ���й�����ȱ���
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
	int i,j,k,adjvex[Max];//��������ͳ�ʼ��
	double lowcost[Max];
	for(i=0;i<p->vertexNum;i++){//��adjvex[]��lowcost[]�����ʼ��
		adjvex[i]=v;    lowcost[i]=p->arc[v][i];
	}
	lowcost[v]=0; //��v���뵽U��   
	//j=MinEdge(lowcost,vertexNum);
	for(k=1;k<p->vertexNum;k++){//k�Ǽ�����������ѭ������������vertexNum��������Ҫ���뵽U��
        for(i=0;i<p->vertexNum;i++)//�����1��ֵ��Ϊ0��lowcost[i]Ϊ��СȨֵ
			if(lowcost[i]) break;
		j=i;//j���ڴ洢��С��lowcost[i]���±�
		for(i=j+1;i<p->vertexNum;i++)//��j֮��ĸ�С��lowcost[i]�������±�i��ֵ��j
			if(lowcost[i]&&lowcost[i]<lowcost[j]) j=i;
		//cout<<'('<<j<<','<<adjvex[j]<<')'<<lowcost[j]<<"  ";
		printf("(%d,%d)%lf  ",j,adjvex[j],lowcost[j]);
		lowcost[j]=0;
		for(i=0;i<p->vertexNum;i++)/*��������shortEdge[n]*/
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
	printf("�����붥������ͱߵ�����:\n");
	scanf("%d%d",&n,&e);
	mUnDiNet *mudn=createMUnDiNet(n,e);
	printf("�Ӷ���A��ʼ����������ȱ���������Ϊ:\n");
	DFS(mudn,0);
	printf("\n");
	clear(mudn);
	printf("�Ӷ���A��ʼ���й�����ȱ���������Ϊ:\n");
    BFS(mudn,0);
	printf("��Prime�������Ӷ���A��ʼ������С�������Ĺ������£�\n");
	Prime(mudn,0);
	deleteMUnDiNet(mudn);
	return 0;
}
