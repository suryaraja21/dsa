#include<stdio.h>
#include<malloc.h>
void push();
void pop();
void display();
struct node{
    int data;
    struct node *next;
};
struct node *nw,*top,*temp;

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

void push(){
    int item;
    printf("\nEnter the item: ");
    scanf("%d",&item);
    if(top->data==0){
        top->data=item;
    }else{
        nw=((struct node *)malloc(sizeof(struct node)));
        nw->data=item;
        nw->next=top;
        top=nw;
    }
}

void pop(){
    if(top->data==0){
        printf("\nUnderflow\n");
    }else{
        top=top->next;
    }
}

void display(){
    temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}