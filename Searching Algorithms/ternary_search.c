
#include <stdio.h>

int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;


        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }


        if (key < ar[mid1]) {

            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {

            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
        return -1;
}

int main()
{
    int a[100],n,l, r, p, key;
    printf("Enter the no of elements : ");
    scanf("%d",&n);
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched : ");
    scanf("%d",&key);

    l=0;

    r=n-1;


    p = ternarySearch(l, r, key, a);

    if (p==-1)
         printf("\nElement not found \n");
    else
    {
        printf("\nElement found \n");
        printf("Index of %d is %d\n", key, p);
    }
}
