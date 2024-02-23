#include<stdio.h>
void eval();
void push(int);
int pop();
char postfix[20];
struct stack
{
	int s[size];
	int top;
}st;
main(){
	st.top=-1;

	printf("enter the postfix expression :");
	scanf("%s",&postfix);
	eval();
	printf("%d",st.s[st.top]);
}


void eval(){
	int i,op1,op2;
	for(i=0;postfix[i]!='\0';i++)
	{
	switch(postfix[i])
	{
	case '+':
	{
	char res;
	op1=pop();
	op2=pop();
	res=(op2)+(op1);
	push(res);
	break;
	}
	case '-':
	{
	char res;
	op1=pop();
	op2=pop();
	res=(op2)-(op1);
	push(res);
	break;
	}
	case '*':
	{
	char res;
	op1=pop();
	op2=pop();
	res=(op2)*(op1);
	push(res);
	break;
	}
	default 
	:push(postfix[i]-48);
	}
	}
	}
	void push(int ele)
	{
	st.top++;
	st.s[st.top]=ele;
	}
	int pop()
	{
	char el;
	el=st.s[st.top];
	st.top--;
	return el;
	}
