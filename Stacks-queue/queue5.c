/* Implementation of dequeue */
#include<stdio.h>
#include<stdlib.h>
#define MAX 1007
int dequeue[MAX];
int front = -1;
int rear = -1;
void insert_front(int item);
void insert_rear(int item);
int del_front();
int del_rear();
void display();
int isEmpty();
int isFull();
int main(){
int choice,item;
    while(1){
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete at front\n");
        printf("4.Delete at rear\n");
        printf("5.Display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&item);
            insert_front(item);
            break;
            case 2:
            scanf("%d",&item);
            insert_rear(item);
            break;
            case 3:
            printf("%d delted from front\n",del_front());
            break;
            case 4:
            printf("%d delted from rear\n",del_rear());
            break;
            case 5:
             display();
             break;
            default:
            exit(1);
        }
    }
    return 0;
}
void insert_rear(int item){
    if(isFull()){
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1)
     front = rear = 0;
    
    else if(rear == MAX-1)
     rear = 0;
    
    else
     rear++;
   dequeue[rear] = item;
}

void insert_front(int item){
    if(isFull()){
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1){
     front = rear=0;
    }
    else if(front == 0)
      front = MAX -1;
    else
      front--;
   dequeue[front] = item;
}

int del_front(){
    if(isEmpty()){
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = dequeue[front];
    if(front == rear){
        front = rear = -1;
    }
    else if(front == MAX-1)
     front =0;
    else
     front++;
return item;
}

int del_rear(){
    if(isEmpty()){
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = dequeue[rear];
    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0)
     rear = MAX-1;
    else
     rear--;
return item;
}

int isEmpty(){
    if(front == -1)
    return 1;
    else 
     return 0;
}

int isFull(){
    if(front ==0 && rear==MAX-1 || front == rear+1)
     return 1;
    else
     return 0;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue Underflow!\n");
        return;
    }
    if(rear< front){
        for(i=front ;i<MAX;i++)
         printf("%d\n",dequeue[i]);
        for(i= 0 ;i<=rear;i++)
         printf("%d\n",dequeue[i]);
    }
    else{
        for(i=front ;i<=rear;i++)
         printf("%d\n",dequeue[i]);
    }
printf("\n\n");
}