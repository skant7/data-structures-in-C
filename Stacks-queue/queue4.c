/* Implementation of circular queue */
#include<stdio.h>
#include<stdlib.h>
#define MAX 1007
int cqueue[MAX];
int front = -1;
int rear = -1;
void insert(int item);
int del();
int peek();
void display();
int isEmpty();
int isFull();    
int main(){
int choice,item;
    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&item);
            insert(item);
            break;
            case 2:
            printf("%d deleted\n",del());
            break;
            case 3:
            printf("%d\n",peek());
            break;
            case 4:
            display();
            break;
            default:
            exit(1);
        }
    }
    return 0;
}

void insert(int item){
   if(isFull()){
       printf("Queue Overflow!\n");
       return;
   }
   if(front == -1)
    front =0;
   if(rear == MAX-1)
    rear = 0;
   else
    rear++;
 cqueue[rear]=item;
}

int del(){
    if(isEmpty()){
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = cqueue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front  == MAX-1)
      front =0;
    else
     front++;
  return item;
}
int peek(){
    if(isEmpty()){
        printf("Queue Underflow!\n");
        exit(1);
    }
    return cqueue[front];
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue Undereflow!\n");
        return;
    }
    printf("Queue contents: \n");
    if(rear < front){
    for( i= front ;i<= MAX-1;i++)
     printf("%d\n",cqueue[i]);
    for(i=0 ;i<=rear;i++)
     printf("%d\n",cqueue[i]);
}
   else{
       for(int i= front;i<=rear;i++)
        printf("%d\n",cqueue[i]);
   }
  printf("\n\n");
}

int isEmpty(){
    if(front == -1)
     return 1;
    else
     return 0;
}

int isFull(){
    if((front==0 && rear == MAX-1) || (front == rear+1))
     return 1;
    else
     return 0;
}