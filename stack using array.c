#include <stdio.h>
#define length 20 
void push();
void pop();
void display();
struct stack{
    int a[length];
    int top;
}st;

int main(){
    st.top=-1;
    int choice,b=1;
    printf("Hii!");
    
    while(b){
        printf("\nEnter your choice 1 push 2 pop 3 display 4 exit: ");
        scanf("%d",&choice);
        if(choice==1){
            push();
        }else if(choice==2){
            pop();
        }else if(choice==3){
            display();
        }else if(choice==4){
            printf("\nThank you ");
            b=0;
        }else{
            printf("Enter a valid choice!!");
        }
    }

}


void push(){
    if(st.top==length-1){
        printf("\nThe Stack is full!");
    }else{
        int data;
        printf("\nEnter the data you want to push into stack: ");
        scanf("%d",&data);
        st.top++;
        st.a[st.top]=data;
        
    }
}

void pop(){
    if(st.top==-1){
        printf("The stack is empty!");
    }else{
        st.top--;
    }
}

void display(){
    if(st.top==-1){
        printf("The stack is empty!");
    }else{
        for(int i=0;i<length;i++){
            printf("%d",st.a[i]);
        }
    }
}