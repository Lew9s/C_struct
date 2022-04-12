#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Linknode{
	ElemType data;
	struct Linknode *next;
}Lnode,*LiStack;

int InitLiStack(LiStack L){
	L=(Lnode*)malloc(sizeof(Lnode));
	if(L==NULL)
	    return 0;
	L->next=NULL;
	return 1;
}

int Push(LiStack L,ElemType x){
	Lnode *s=(Lnode*)malloc(sizeof(Lnode));
	if(s==NULL)
        return 0;
	s->data=x;
	s->next=L->next;
	L->next=s;
	return 1;
}

int Pop(LiStack L){
	if(L->next==NULL)
	    return 0;
	Lnode*s=L->next;
	ElemType x=s->data;
	L->next=L->next->next;
	free(s);
	return x;
}

int GetTop(LiStack L){
	if(L->next==NULL)
	    return 0;
	ElemType x=L->next->data;
	return x;
}

int main(){
	LiStack L;
	InitLiStack(L);
}
