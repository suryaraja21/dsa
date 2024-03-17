#include<stdio.h>
#include<malloc.h>
void push();
void pop();
void display();
struct node{
    int data;
    struct node *next;
};
struct node *top=0,*nw,*temp;

void push(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    nw=((struct node *)malloc(sizeof(struct node)));
    nw->data=data;
    nw->next=top;
    top=nw;
}
void display(){
    temp=top;
    if(top==NULL)
    printf("Stack is empty!;");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}


void pop(){
    temp=top;
    if(top==NULL)
    printf("Stack is empty!");
    else{
         top=top->next;
    }
}

main(){
    int choice;
    nw=((struct node *)malloc(sizeof(struct node)));
    nw->data=0;
    nw->next=0;
    top=nw;
    do{
        printf("\n\nEnter your choice:\n1)push\n2)pop\n3)Display: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
        }
    }while(choice<=3);
}
    

