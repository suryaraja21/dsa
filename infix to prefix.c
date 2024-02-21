#include <stdio.h>
#include <string.h>

char revinfix[20];
void post();
void push(int);
char pop();
char infix[20], prefix[20];
struct stack
{
    int s[20];
    int top;
} st;
main()
{
    st.top = -1;
    int i = 0;
    printf("enter the infix expression:");
    gets(infix);

    post();
}

void post()
{
    int i, j = 0;
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        switch (infix[i])
        {
        case '+':
        {
            while (st.s[st.top] >= 3)
                prefix[j++] = pop();
            push(1);
            break;
        }
        case '-':
        {
            while (st.s[st.top] >= 3)
                prefix[j++] = pop();
            push(2);
            break;
        }
        case '*':
        {
            while (st.s[st.top] >= 4)
                prefix[j++] = pop();
            push(3);
            break;
        }
        case '/':
        {
            while (st.s[st.top] >= 4)
                prefix[j++] = pop();
            push(4);
            break;
        }
        case '^':
        {
            while (st.s[st.top] > 5)
                prefix[j++] = pop();
            push(5);
            break;
        }
        case ')':
        {
            push(0);
            break;
        }
        case '(':
        {
            while (st.s[st.top] != 0)
                prefix[j++] = pop();
            st.top--;
            break;
        }
        default:
            prefix[j++] = infix[i];
        }
    }
    while (st.top >= 0)
        prefix[j++] = pop();
    printf("the prefix expression is %s", strrev(prefix));
}
void push(int ele)
{
    st.top++;
    st.s[st.top] = ele;
}
char pop()
{
    int el;
    char e;
    el = st.s[st.top];
    st.top--;
    switch (el)
    {
    case 1:
        e = '+';
        break;
    case 2:
        e = '-';
        break;
    case 3:
        e = '*';
        break;
    case 4:
        e = '/';
        break;
    case 5:
        e = '^';
        break;
    }
    return (e);
}