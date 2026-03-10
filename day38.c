#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Insert at front
void push_front(int value)
{
    if(front == 0)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void push_back(int value)
{
    if(rear == MAX-1)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void pop_front()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// Delete from rear
void pop_back()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

// Display elements
void display()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}