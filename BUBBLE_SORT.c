#include<stdio.h>
#define size 5

main(){
    int arr[size],i,j,temp;
    for(i=0;i<size;i++){
        printf("Enter the element %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array is: \n");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);


    //SORTING BEGINS:


    for(i=0;i<size;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
 printf("\nThe sorted array is: \n");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);
}