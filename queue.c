#include<stdio.h>
#define size 20 
void del();
void insert();
void display();
struct queue{
    int a[size];
    int front,rear;
}q;


void insert(){
    int item;
    
    if(q.rear==size){
        printf("Queue is full!");
    }else if(q.rear==-1){
        printf("Enter the item: ");
        scanf("%d",&item);
        q.front++;
        q.rear++;
        q.a[q.rear]=item;
    }else{
        printf("Enter the item: ");
        scanf("%d",&item);
        q.rear++;
        q.a[q.rear]=item;
    }
}

void del(){
    if(q.rear==-1){
        printf("Queue is empty!");
    }else if(q.front==q.rear){
        
        q.rear=-1;
        q.front=-1;
    }
    else{
        q.front++;
    }
}

void display(){
    int temp=q.front;
    if(q.rear==-1){
        printf("Queue is empty!");
    }else{
        for(int i=q.front;i<q.rear+1;i++){
            printf("%d ",q.a[i]);
        }
    }
}

main(){
    int choice,b=1;
    printf("Hii!");
    q.front=-1;
    q.rear=-1;
    while(b){
        printf("\nEnter your choice 1 push 2 pop 3 display 4 exit: ");
        scanf("%d",&choice);
        if(choice==1){
            insert();
        }else if(choice==2){
            del();
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
