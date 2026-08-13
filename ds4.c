
//Given an array of integers, rearrange the elements such that all even numbers appear before all odd numbers while preserving their relative order. 

#include <stdio.h>

int main()
{
    int n,i,j=0;
    int arr[100],result[100];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (i =0;i<n;i++)
    {
        if (arr[i]%2==0)
        {
            result[j]=arr[i];
            j++;
        }
    }
    for (i=0;i<n;i++)
    {
        if (arr[i]%2!=0)
        {
            result[j] = arr[i];
            j++;
        }
    }
    printf("Rearranged Array:\n");
    for (i=0;i<n;i++)
    {
        printf("%d",result[i]);
    }
    return 0;
}
