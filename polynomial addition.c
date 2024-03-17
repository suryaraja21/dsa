#include <stdio.h>
#include <malloc.h>
void creation_of_p1();
void creation_of_p2();
void add_p1_p2();
void display_p3();
// structure of node
struct node
{
    int coeff, pow;
    struct node *next;
};
struct node *nw1,*head1, *tail1, *nw2,*head2, *tail2, *temp1, *temp2, *nw3, *head3, *tail3, *temp3;
// creation of p1
void creation_of_p1()
{
    int n, i, coeff, pow;
printf("\nenter the number of terms");
scanf("%d",&n);
for(i=0;i<n;i++)
{
        printf("\nenter the coeff");
        scanf("%d", &coeff);
        scanf("%d", &pow);
        if (head1->coeff == 0)
        {
            head1->coeff = coeff;
            head1->pow = pow;
        }
        else
        {
            nw1 = ((struct node *)malloc(sizeof(struct node)));
            nw1->coeff = coeff;
            nw1->pow = pow;
            tail1->next = nw1;
            nw1->next = NULL;
            tail1 = nw1;
        }}
}
// creation of p2
void creation_of_p2()
{
    int m, i, coeff, pow;
printf("\nenter the number of terms");
scanf("%d",&m);
for(i=0;i<m;i++)
{
        printf("\nenter the coeff");
        scanf("%d", &coeff);
        scanf("%d", &pow);
        if (head2->coeff == 0)
        {
            head2->coeff = coeff;
            head2->pow = pow;
        }
        else
        {
            nw2 = ((struct node *)malloc(sizeof(struct node)));
            nw2->coeff = coeff;
            nw2->pow = pow;
            tail2->next = nw2;
            nw2->next = NULL;
            tail2 = nw2;
        }}
}
void add_p1_p2()
{
    temp1 = head1;
    temp2 = head2;
    while ((temp1 != NULL) && (temp2 != NULL))
    {
        if (temp1->pow == temp2->pow){
           if (head3->coeff == 0){
                head3->coeff = temp1->coeff+temp2->coeff;
                head3->pow = temp1->pow;  //or temp2->pow;
            }else{
                nw3 = ((struct node *)malloc(sizeof(struct node)));
                nw3->coeff = temp1->coeff+temp2->coeff;
                nw3->pow = temp1->pow;
                tail3->next = nw3;
                nw3->next = NULL;
                tail3 = nw3;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }else if (temp1->pow > temp2->pow){
            if (head3->coeff == 0){
                head3->coeff = temp1->coeff;
                head3->pow = temp1->pow;  //or temp2->pow;
            }else{
                nw3 = ((struct node *)malloc(sizeof(struct node)));
                nw3->coeff = temp1->coeff;
                nw3->pow = temp1->pow;
                tail3->next = nw3;
                nw3->next = NULL;
                tail3 = nw3;
                temp1=temp1->next;
            }
    }
    else{
        if (head3->coeff == 0){
                head3->coeff =temp2->coeff;
                head3->pow = temp2->pow;  //or temp2->pow;
            }else{
                nw3 = ((struct node *)malloc(sizeof(struct node)));
                nw3->coeff =temp2->coeff;
                nw3->pow = temp2->pow;
                tail3->next = nw3;
                nw3->next = NULL;
                tail3 = nw3;
                temp2=temp2->next;
            }
        }
    }
    while (temp1 != NULL)
    {
        nw3=((struct node *)malloc(sizeof(struct node)));
        nw3->coeff =temp1->coeff;
        nw3->pow = temp1->pow;
        tail3->next = nw3;
        nw3->next = NULL;
        tail3 = nw3;
        temp1=temp1->next;
        
    }
    while (temp2 != NULL)
    {
        nw3 = ((struct node *)malloc(sizeof(struct node)));
        nw3->coeff = temp2->coeff;
        nw3->pow = temp2->pow;
        tail3->next = nw3;
        nw3->next = NULL;
        tail3 = nw3;
        temp2=temp2->next;
    }
}

void display_p3(){
    temp3=head3;
    while(temp3!=NULL){
        printf("%dx^%d  ",temp3->coeff,temp3->pow);
        temp3=temp3->next;
    }
}
main()
{
    nw1 = ((struct node *)malloc(sizeof(struct node)));
    nw1->coeff = 0;
    nw1->pow = 0;
    nw1->next = NULL;
    head1 = nw1;
    tail1 = nw1;
    
    nw2 = ((struct node *)malloc(sizeof(struct node)));
    nw2->coeff = 0;
    nw2->pow = 0;
    nw2->next = NULL;
    head2 = nw2;
    tail2 = nw2;


    nw3 = ((struct node *)malloc(sizeof(struct node)));
    nw3->coeff = 0;
    nw3->pow = 0;
    nw3->next = NULL;
    head3 = nw3;
    tail3 = nw3;


    creation_of_p1();
    creation_of_p2();
    add_p1_p2();
    display_p3();
}
