#include<stdio.h>
#include<string.h> 
#define Max 50
typedef struct{//����˳��ջ 
	char data[Max];
	int length;
}SqString;
void InitString(SqString *str1,char *s2){//����ʼ�� 
	strcpy(str1->data,s2);
	str1->length=strlen(s2);
}
int Index(SqString s,SqString t){//����(��)ƥ���㷨 
	int i=0,j=0;
	while(i<s.length && j<t.length){
		if(s.data[i]==t.data[j]){ i++;j++;	}
		else{ i=i-j+1;   j=0;		}
	}
	if(j>=t.length) return (i-t.length);
	else return -1;
}

void GetNext(SqString t,int next[]){
//��ģʽ��t�������next��Ԫ��ֵ������1λ����next[0]����Ϊ-1 
	int j=0,k=-1; 
	next[0]=-1;	//next���飬��������1λ�ķ���
	while(j<t.length-1){//O(m) 
		if(k==-1||t.data[j]==t.data[k]){//���ִ��||���ұߣ���||��߱�ȻΪ�� 
			j++;  k++;  next[j]=k;
		}
		else k=next[k];
	} 
}
int KMPIndex(SqString s,SqString t){//KMP�㷨 ,next����Ԫ������1λ 
	int next[Max],i=0,j=0;
	GetNext(t,next);
	while(i<s.length && j<t.length){
		if(j==-1||s.data[i]==t.data[j]){
			i++;  j++;
		}
		else j=next[j];
	}
	if(j>=t.length) return (i-t.length);
	else return -1;
}

void GetNextval(SqString t,int nextval[]){
//��ģʽ��t�������nextval��Ԫ��ֵ������Ԫ������1λ 
	int j=0,k=-1; 
	nextval[0]=-1;
	while(j<t.length){
		if(k==-1||t.data[j]==t.data[k]){
			j++;  k++;
			if(t.data[j]!=t.data[k])
				nextval[j]=k;
			else
				nextval[j]=nextval[k];
		}
		else
			k=nextval[k];
	}	
} 
int KMPIndex1(SqString s,SqString t){//�Ľ���KMP�㷨������Ԫ������1λ 
	int nextval[Max],i=0,j=0;
	GetNextval(t,nextval);
	while(i<s.length && j<t.length){
		if(j==-1 || s.data[i]==t.data[j]){
			i++;  j++;
		}
		else  j=nextval[j];
	}
	if(j>=t.length)  return (i-t.length);
	else return -1;
}

void GetNext2(SqString t,int next[]){//��ģʽ��t�������next2��Ԫ��ֵ 
	int j=0,i; 
	next[0]=0;
	for(i=1;i<t.length;++i){
		while(j>0 && t.data[i]!=t.data[j])
			j=next[j-1];
		if(t.data[i]==t.data[j]) j++;
		next[i]=j;
	} 
}
int KMPIndex2(SqString s,SqString t){//KMP�㷨2��next���鲻����1λ 
	int next[Max],i=0,j=0;
	GetNext2(t,next);
	while(i<s.length && j<t.length){
		if(j==0&&s.data[i]!=t.data[j]||s.data[i]==t.data[j]){
			i++;  j++;
		}
		else j=next[j-1];
	}
	if(j>=t.length) return (i-t.length);
	else return -1;
}
void GetNext3(SqString t,int next[]){//��ģʽ��t�������next3��Ԫ��ֵ-1 
	int j=0,i; 
	next[0]=0;
	for(i=1;i<t.length;++i){
		while(j>0 && t.data[i]!=t.data[j])
			j=next[j-1];
		if(t.data[i]==t.data[j]) j++;
		next[i]=j;
	}
	for(j=0;j<t.length;++j) next[j]-=1; 
}
int KMPIndex3(SqString s,SqString t){//KMP�㷨3��next3�����Ԫ��-1 
	int next[Max],i=0,j=0;
	GetNext3(t,next);
	while(i<s.length && j<t.length){
		if(j==-1||s.data[i]==t.data[j]){
			i++;  j++;
		}
		else j=next[j-1]+1;
	}
	if(j>=t.length) return (i-t.length);
	else return -1;
}
int main(){
	int j;
	int next3[Max],next2[Max],next[Max],nextval[Max];
	SqString s,t;
	char s1[Max]="abcabcdabcdeabcdefabcdefg";
	char t1[Max]="abcdeabcdefab";
	InitString(&s,s1);
	InitString(&t,t1);
	printf("��s:%s\n",s.data);
	printf("��t:%s\n",t.data);
	printf("����ƥ���㷨:\n");
	printf("��t�ڴ�s�е���ʼ�±�=%d\n",Index(s,t));
	GetNext3(t,next3);//��ģʽ��t���next3�����Ԫ��ֵ-1�������� 
	GetNext2(t,next2);//��ģʽ��t���next2�����Ԫ��ֵ�������� 
	GetNext(t,next);//��ģʽ��t���next�����Ԫ��ֵ,����1λ 
	GetNextval(t,nextval);//��ģʽ��t���nextval�����Ԫ��ֵ 
	printf("    j    ");
	for(j=0;j<t.length;++j)
		printf("%4d",j);
	printf("\n");
	printf(" t[j]    ");
	for(j=0;j<t.length;++j)
		printf("%4c",t.data[j]);
	printf("\n");
	printf("next3    ");
	for(j=0;j<t.length;++j)
		printf("%4d",next3[j]);
	printf("\n");
	printf("next2    ");
	for(j=0;j<t.length;++j)
		printf("%4d",next2[j]);
	printf("\n");
	printf("next     ");
	for(j=0;j<t.length;++j)
		printf("%4d",next[j]);
	printf("\n");
	printf("nextval  ");
	for(j=0;j<t.length;++j)
		printf("%4d",nextval[j]);
	printf("\n");
	printf("KMP�㷨-next����Ԫ��-1�������ƣ�\n");
	printf("��t�ڴ�s�е���ʼ�±�=%d\n\n",KMPIndex3(s,t));
	printf("KMP�㷨-next���鲻���ƣ�\n");
	printf("��t�ڴ�s�е���ʼ�±�=%d\n\n",KMPIndex2(s,t));	
	printf("KMP�㷨-next��������1λ��\n");
	printf("��t�ڴ�s�е���ʼ�±�=%d\n\n",KMPIndex(s,t));	
	printf("�Ľ���KMP�㷨������Ԫ������1λ��\n");
	printf("��t�ڴ�s�е���ʼ�±�=%d\n\n",KMPIndex1(s,t));	
	return 0;
}
