#include<stdio.h>
#define size 5

main(){
    int arr[size],i,j,min,temp;
    for(i=0;i<size;i++){
        printf("Enter the element %d ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array is: \n");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);


    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++)
            if(arr[j]<arr[min])
                min=j;
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

    
}

    printf("\nThe sorted array is: \n");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);
}
