#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Push an element */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

/* Pop an element */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

/* Peek at the top element */
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

/* Count number of elements */
int count()
{
    return top + 1;
}

/* Find sum of all elements */
int sum()
{
    int i;
    int total = 0;

    for (i = 0; i <= top; i++)
    {
        total = total + stack[i];
    }

    return total;
}

/* Find maximum element */
int maximum()
{
    int i;
    int max;

    if (top == -1)
    {
        return 0;
    }

    max = stack[0];

    for (i = 1; i <= top; i++)
    {
        if (stack[i] > max)
        {
            max = stack[i];
        }
    }

    return max;
}

/* Display stack */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");

        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    peek();

    printf("Number of elements = %d\n", count());
    printf("Sum of elements = %d\n", sum());
    printf("Maximum element = %d\n", maximum());

    pop();

    display();

    return 0;
}

