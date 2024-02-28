#include <stdio.h>
#define size 20

void display1();void display2();
void push1();void push2();
void pop1();void pop2();
struct stack{
    int arr[size];
    int top1,top2;
}st;

main(){
    st.top1=-1;
    st.top2=-1;
    int choice,n,i=1;
    while(i){
        printf("\n\n\n1 Insertion 2 Deletion 3 Display 4 Exit: \n");
        printf("Enter your choice and stack you want to access: ");
        scanf("%d %d",&choice,&n);
        if(choice==1 && n==1)
        push1();
        else if(choice==1 && n==2)
        push2();
        else if(choice==2 && n==1)
        pop1();
        else if(choice==2 && n==2)
        pop2();
        else if(choice==3 && n==1)
        display1();
        else if(choice==3 && n==2)
        display2();
        else if(choice==4)
        i=0;
        else
        printf("Enter a valid choice!\n");
    }
}

void push1(){
    int item;
    if(st.top1==(size/2)-1)
    printf("Stack 1 is full! \n");
    else{
        printf("Enter the item: ");
        scanf("%d",&item);
        st.top1++;
        st.arr[st.top1]=item;
    }
}

void push2(){
    int item;
    if(st.top2==size-1)
    printf("Stack 2 is empty! \n");
    else{
        printf("Enter the item: ");
        scanf("%d",&item);
        if(st.top2==-1)
        st.top2=(size/2);
    }
    st.top2++;
    st.arr[st.top2]=item;
}

void pop1(){
    if(st.top1==-1)
    printf("STACK 1 IS EMPTY! \n");
    else
    st.top1--;
}

void pop2(){
    if(st.top2==-1)
    printf("Stack 2 is empty! \n");
    else{
        if(st.top2==(size/2))
        st.top2=-1;
        else
        st.top2--;
    }
}

void display1(){
    int i;
    if(st.top1==-1)
    printf("Stack 1 is empty! \n");
    else{
        for(i=0;i<st.top1+1;i++){
        if(st.arr[i]!='\0')
        printf("%d ",st.arr[i]);
        }
    }
}

void display2(){
    int i;
    if(st.top2==-1)
    printf("Stack 2 is empty! \n");
    else{
        for(i=size/2;i<st.top2+1;i++)
        if(st.arr[i]!='\0')
        printf("%d ",st.arr[i]);
        
    }
}