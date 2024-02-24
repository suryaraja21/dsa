#include <stdio.h>
#include <string.h>
#define size 20
void eval();
void push(int);
int pop();
char prefix[20];
struct stack
{
    int s[size];
    int top;
} st;
main()
{
    st.top = -1;
    printf("enter the prefix expression :");
    gets(prefix);
    eval();
    printf("%d", st.s[st.top]);
}

void eval()
{
    int i, op1, op2;
    for (i = strlen(prefix); i >= 0; i--)
    {
        switch (prefix[i])
        {
        case '+':
        {
            char res;
            op1 = pop();
            op2 = pop();
            res = (op1) + (op2);
            push(res);
            break;
        }
        case '-':
        {
            char res;
            op1 = pop();
            op2 = pop();
            res = (op1) - (op2);
            push(res);
            break;
        }
        case '*':
        {
            char res;
            op1 = pop();
            op2 = pop();
            res = (op1) * (op2);
            push(res);
            break;
        }
        default:
            push(prefix[i] - 48);
        }
    }
}
void push(int ele)
{
    st.top++;
    st.s[st.top] = ele;
}
int pop()
{
    char el;
    el = st.s[st.top];
    st.top--;
    return el;
}