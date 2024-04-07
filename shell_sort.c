#include<stdio.h>
int main(){
    int i,n,gap,arr[10],temp,j;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the array values: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("|The array before sorting: ");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    //sorting

    for(gap=n/2;gap>0;gap=gap/2){
        for(i=gap;i<n;i++){
            temp=arr[i];
            for(j=i;j>=gap&&arr[j-gap]>temp;j=j-gap)
            arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
    printf("\nAfter sorting: ");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);

}