#include<stdio.h>
#include<stdlib.h>
int n;

struct node{
    int data;
    struct node *prev, *next;
};

struct node *head, *tail, *nw, *temp, *temp1;
void creation();
void creation(){
    int i;
    head=((struct node *)malloc(sizeof(struct node)));
    head->data=0;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the data: ");
        if(head->data==0){
            scanf("%d",&head->data);
            head->prev=NULL;
            head->next=NULL;
            tail=head;
        }else{
            nw=((struct node *)malloc(sizeof(struct node)));
            scanf("%d",&nw->data);
            tail->next=nw;
            nw->prev=tail;
            nw->next=NULL;
            tail=nw;
        }
    }
}

void display();

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void deletion(){
    int pos,i;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos==0){
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }else if (pos==n-1)
    {
        temp=tail;
        tail=tail->prev;
        temp->prev=NULL;
        tail->next=NULL;
    }else{
        temp=head;
        for(i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp1=temp->next->next;
        temp->next=temp1;
        temp1->prev=temp;
        
    }
    
}
void insertion();
void insertion(){
    int pos,i;
    printf("Enter the position: ");
    scanf("%d",&pos);
    nw=((struct node * )malloc(sizeof(struct node)));
    printf("Enter the data: ");
    scanf("%d",&nw->data);
    if(pos==0){
        nw->prev=NULL;
        nw->next=head;
        head->prev=nw;
        head=nw;
    }else if(pos==n-1){
        tail->next=nw;
        nw->prev=tail;
        nw->next=NULL;
    }else{
        temp=head;
        for(i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=nw;
        nw->prev=tail;
        nw->next=temp1;
        temp1->prev=nw;
    }
}
main(){
    creation();
    display();
    printf("\nDeletion: ");
    deletion();
    display();
    printf("\nInsertion: ");
    insertion();
    display();
}
