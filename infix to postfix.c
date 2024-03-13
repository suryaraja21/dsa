
#include<stdio.h>

void post();
void push(int);
char pop();
char infix[20],postfix[20];


struct stack{
    int s[20];
    int top;
}st;



main(){
    st.top=-1;
    printf("enter the infix expression:");
    scanf("%s",&infix);
    post();
}



void post(){
    int i,j=0;
    for(i=0;infix[i]!='\0';i++){
        switch(infix[i]){
            case '+':{
                while(st.s[st.top]>=1)
                postfix[j++]=pop();
                push(1);
                break;
            }
            case '-':{
                while(st.s[st.top]>=1)
                postfix[j++]=pop();
                push(2);
                break;
            }
            case '*':{
                while(st.s[st.top]>=3)
                postfix[j++]=pop();
                push(3);
                break;
            }
            case '/':{
                while(st.s[st.top]>=3)
                postfix[j++]=pop();
                push(4);
                break;
            }
            case '^':{
                while(st.s[st.top]>=4)
                postfix[j++]=pop();
                push(5);
                break;
            }
            case '(':{
                push(0);
                break;
            }   
            case ')':{
                while(st.s[st.top]!=0)
                postfix[j++]=pop();
                st.top--;
                break;
            }
            default :postfix[j++]=infix[i];
        }
    }
while(st.top>=0)
    postfix[j++]=pop();
printf("the postfix expression is %s",postfix);
}


void push(int ele){
    st.top++;
    st.s[st.top]=ele;
}


char pop(){
    int el;
    char e;
    el=st.s[st.top];
    st.top--;
    switch(el){
        case 1:e='+';
        break;
        case 2:e='-';
        break;
        case 3:e='*';
        break;
        case 4:e='/';
        break;
        case 5:e='^';
        break;
    }
    return(e);
}
