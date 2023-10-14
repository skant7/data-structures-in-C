#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop()
{

    struct node *temp;

    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", top->data);
        temp = top;
        top = top->next;
        free(temp);
    }
}


void printList()
{
    struct node *temp =top;

    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Linked List\n");
    printList();
    pop();
    printf("After the pop, the new linked list\n");
    printList();
    pop();
    printf("After the pop, the new linked list\n");
    printList();

    return 0;
}
