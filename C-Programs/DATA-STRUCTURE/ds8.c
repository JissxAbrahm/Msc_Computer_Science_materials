#include <stdio.h>

int reverseNumber(int n)
{
    int reverse=0;
    int digit;
    while (n!=0)
    {
        digit=n%10;
        reverse=reverse*10+digit;
        n=n/10;
    }
    return reverse;
}

int main()
{
    int n,result;

    printf("Enter a number: ");
    scanf("%d",&n);

    result=reverseNumber(n);

    printf("Reverse=%d",result);
    return 0;
}
