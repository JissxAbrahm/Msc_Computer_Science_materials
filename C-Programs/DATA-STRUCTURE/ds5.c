#include <stdio.h>
int main()
{
    int n, i, j;
    int arr[100];
    int visited[100] = {0};
    int count;
    int maxFrequency = 0;
    int maxElement;
	printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Frequency of Elements:\n");
    for (i=0;i<n;i++)
    {
        if (visited[i]==1)
        {
            continue;
        }
        count = 1;
        for (j=i+1;j<n;j++)
        {
            if (arr[i]==arr[j])
            {
                count++;
                visited[j]=1;
            }
        }
       printf("%d->%d\n",arr[i],count);
        if (count>maxFrequency)
        {
            maxFrequency=count;
            maxElement=arr[i];
        }
    }
    printf("Highest Frequency Element:%d (Frequency = %d)\n",
           maxElement,maxFrequency);

    return 0;
}
