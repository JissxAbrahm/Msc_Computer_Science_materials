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
        printf("Popped element = %d\n", stack[top]);
        top--;
    }
}

/* Display stack normally */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");

        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

/* Display stack in reverse order */
void reverseDisplay()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Reverse order: ");

        for (i = 0; i <= top; i++)
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

    reverseDisplay();

    /* Display again to show stack is unchanged */
    display();

    return 0;
}

