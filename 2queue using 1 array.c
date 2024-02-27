#include<stdio.h>
#define size 6

void insert1();void insert2();
void deletion1();void deletion2();
void display1();void display2();
struct queue{
    int arr[size];
    int front1,front2,rear1,rear2;
}q;

main(){
    q.front1=-1;q.rear1=-1;q.rear2=-1;q.front2=-1;
    int choice,n,i=1;
    while(i){
        printf("\n\n\n1 Insertion 2 Deletion 3 Display 4 Exit: \n");
        printf("Enter your choice and queue you want to access: ");
        scanf("%d %d",&choice,&n);
        if(choice==1 && n==1)
        insert1();
        else if(choice==1 && n==2)
        insert2();
        else if(choice==2 && n==1)
        deletion1();
        else if(choice==2 && n==2)
        deletion2();
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


void display1(){
    if(q.front1==-1){
        printf("Queue 1 is empty! \n");
    }else{
    int i=q.front1;
    for(i=q.front1;i<q.rear1+1;i++)
    printf("%d ",q.arr[i]);
    }
    printf("\n");
}

void display2(){
    if(q.front2==-1){
        printf("Queue 2 is empty! \n");
    }else{
    int i=q.front2;
    for(i=q.front2;i<q.rear2+1;i++)
    printf("%d ",q.arr[i]);
    }
    printf("\n");
}

void insert1(){
    int item;
    if(q.rear1==(size/2)-1)
    printf("Queue 1 is full!\n");
    else if(q.front1==-1){
        q.front1++;
        q.rear1++;
        printf("Enter the item: ");
        scanf("%d",&item);
        q.arr[q.rear1]=item;
    }else{
        q.rear1++;
        printf("Enter the item: ");
        scanf("%d",&item);
        q.arr[q.rear1]=item;
    }
}

void insert2(){
    int item;
    if(q.rear2==size-1)
    printf("Queue 2 is full!\n");
    else if(q.front2==-1){
        q.front2=size/2;
        q.rear2=size/2;
        printf("Enter the item: ");
        scanf("%d",&item);
        q.arr[q.rear2]=item;
    }else{
        q.rear2++;
        printf("Enter the item: ");
        scanf("%d",&item);
        q.arr[q.rear2]=item;
    }
}

void deletion1(){
    if(q.front1==-1)
    printf("Queue 1 is empty!\n");
    else if(q.front1==q.rear1){
        q.front1=-1;
        q.rear1=-1;
    }
    else{
        q.front1++;
    }
}

void deletion2(){
    if(q.front2==-1)
    printf("Queue 2 is empty!\n");
    else if(q.front2==q.rear2){
        q.front2=-1;
        q.rear2=-1;
    }
    else{
        q.front2++;
    }
}
