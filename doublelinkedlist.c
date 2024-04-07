#include<stdio.h>
#include<malloc.h>
int n;
int i;
void create();
void display();
void deletion();
struct node{
    int data;
    struct node *next, *prev;
};
struct node *head,*tail, *nw, *temp1, *temp2, *temp;

void create(){
    int i,item;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the item: ");
        scanf("%d",&item);
        if(head->data==0){
            head->data=item;
        }else{
            nw=((struct node*)malloc(sizeof(struct node)));
            nw->data=item;
            nw->next=NULL;
            nw->prev=tail;
            tail->next=nw;
            tail=nw;
        }
    }
}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void insert(){
    int pos,item;
    nw=((struct node *)malloc(sizeof(struct node)));
    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("Enter the item: ");
    scanf("%d",item);
    nw->data=item;
    if(pos==0){
        nw->prev=NULL;
        nw->next=head;
        head->prev=nw;
        head=nw;
    }else if(pos==n-1){
        nw->next=NULL;
        nw->prev=tail;
        tail->next=nw;
        tail=nw;
    }else{
        temp1=head;
        for(i=0;i<pos-1;i++){
            temp1=temp1->next;
            temp1->next=nw;
            nw->prev=temp1;
            nw->next=temp2;
            temp2->prev=nw;
        }
    }        
}

void deletion(){
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos==0){
        temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        free(temp);
    }else if(pos==n-1){
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        free(temp);
    }else{
        temp1=head;
        for(i=0;i<pos-1;i++){
            temp1=temp1->next;
        }
        temp1=temp1->next;
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp1=temp2->next;
        temp1->prev=temp2->next;
        temp1->prev=temp2->prev;
        temp2->prev=NULL;
        temp2->next=NULL;
        free(temp2);
    }
}

int main(){
    create();
    display();
    deletion();
}