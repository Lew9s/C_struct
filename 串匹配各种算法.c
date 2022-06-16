#include<stdio.h>
#include<string.h> 
#define Max 50
typedef struct{//定义顺序栈 
	char data[Max];
	int length;
}SqString;
void InitString(SqString *str1,char *s2){//串初始化 
	strcpy(str1->data,s2);
	str1->length=strlen(s2);
}
int Index(SqString s,SqString t){//暴力(简单)匹配算法 
	int i=0,j=0;
	while(i<s.length && j<t.length){
		if(s.data[i]==t.data[j]){ i++;j++;	}
		else{ i=i-j+1;   j=0;		}
	}
	if(j>=t.length) return (i-t.length);
	else return -1;
}

void GetNext(SqString t,int next[]){
//由模式串t求出数组next各元素值，右移1位，将next[0]设置为-1 
	int j=0,k=-1; 
	next[0]=-1;	//next数组，采用右移1位的方法
	while(j<t.length-1){//O(m) 
		if(k==-1||t.data[j]==t.data[k]){//如果执行||的右边，则||左边必然为假 
			j++;  k++;  next[j]=k;
		}
		else k=next[k];
	} 
}
int KMPIndex(SqString s,SqString t){//KMP算法 ,next数组元素右移1位 
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
//由模式串t求出数组nextval各元素值，数组元素右移1位 
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
int KMPIndex1(SqString s,SqString t){//改进的KMP算法，数组元素右移1位 
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

void GetNext2(SqString t,int next[]){//由模式串t求出数组next2各元素值 
	int j=0,i; 
	next[0]=0;
	for(i=1;i<t.length;++i){
		while(j>0 && t.data[i]!=t.data[j])
			j=next[j-1];
		if(t.data[i]==t.data[j]) j++;
		next[i]=j;
	} 
}
int KMPIndex2(SqString s,SqString t){//KMP算法2，next数组不右移1位 
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
void GetNext3(SqString t,int next[]){//由模式串t求出数组next3各元素值-1 
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
int KMPIndex3(SqString s,SqString t){//KMP算法3，next3数组各元素-1 
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
	printf("串s:%s\n",s.data);
	printf("串t:%s\n",t.data);
	printf("暴力匹配算法:\n");
	printf("串t在串s中的起始下标=%d\n",Index(s,t));
	GetNext3(t,next3);//由模式串t求出next3数组各元素值-1，不右移 
	GetNext2(t,next2);//由模式串t求出next2数组各元素值，不右移 
	GetNext(t,next);//由模式串t求出next数组各元素值,右移1位 
	GetNextval(t,nextval);//由模式串t求出nextval数组各元素值 
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
	printf("KMP算法-next数组元素-1，不右移：\n");
	printf("串t在串s中的起始下标=%d\n\n",KMPIndex3(s,t));
	printf("KMP算法-next数组不右移：\n");
	printf("串t在串s中的起始下标=%d\n\n",KMPIndex2(s,t));	
	printf("KMP算法-next数组右移1位：\n");
	printf("串t在串s中的起始下标=%d\n\n",KMPIndex(s,t));	
	printf("改进的KMP算法，数组元素右移1位：\n");
	printf("串t在串s中的起始下标=%d\n\n",KMPIndex1(s,t));	
	return 0;
}
