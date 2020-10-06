#include <stdio.h>

int lin_search(int arr[], int n, int x)
{
    int i=0;
    while(i<n && arr[i]!=x)
        i++;
    if(i<n){
        printf("Element found at index : %d ",i);
    }
    else{
         printf("Element not found !!! ");
    }

}
int main()
{
    int a[100],n,key;
    printf("Enter the no of elements : ");
    scanf("%d",&n);
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched : ");
    scanf("%d",&key);
    lin_search(a,n,key);
    return 0;
}
