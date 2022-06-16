#include<stdio.h>
typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}linkStack;
linkStack * InitStack(){
	linkStack *top=NULL;
	return top;
}
void DestroyStack(linkStack *top){
	linkStack *p=top;
	while(p){
		top=top->next;
		free(p);
		p=top;
	}
}
int stackEmpty(linkStack *top){
	return (!top?1:0);
}
linkStack * Push(linkStack *top,ElemType x){
	linkStack *s = (linkStack *)malloc(sizeof(linkStack));
	s->data=x; 
	s->next=top;
	top=s;
	return top;
}
int Pop(linkStack *top,ElemType *x){
	if(!top) { printf("栈空\n");  return 0;	}
	*x=top->data;
	linkStack *p=top;
	top=top->next;
	free(p);
	return 1;
}
int getTop(linkStack *top,ElemType *x){
	if(!top) { printf("栈空\n");  return 0;	}
	*x=top->data;
	return 1;
}
main(){
	ElemType x;
	linkStack *LS = InitStack();
	printf("%d\n",stackEmpty(LS));//1
	LS=Push(LS,100);
	printf("%d\n",stackEmpty(LS));//0
	printf("%d,%d\n",getTop(LS,&x),x);//1,100,实际结果是1,0,分析原因，找出错误，改进 
	/*int i;
	for(i=1;i<4;++i)
		Push(LS,i);
	
	printf("%d\n",stackEmpty(LS));//0
	printf("%d,%d\n",getTop(LS,&x),x);//1,3
	printf("%d,%d\n",Pop(LS,&x),x);//1,3
	printf("%d,%d\n",Pop(LS,&x),x);//1,2
	printf("%d,%d\n",Pop(LS,&x),x);//1,1
	printf("%d,%d\n",getTop(LS,&x),x);//栈空\n  0,1
	*/
	return 0;
}
