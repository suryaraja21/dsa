#include<stdio.h>
#define size 5
main(){
    int arr[size];
    int i,j,temp;
    for(i=0;i<size;i++){
        printf("Enter the element %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array is: \n");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);
//SORTING BEGINS:
    for(i=1;i<size;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
    printf("\nThe sorted array is: \n");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);
}