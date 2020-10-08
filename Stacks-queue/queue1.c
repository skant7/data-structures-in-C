#include<stdio.h>
#include<stdlib.h>
#define MAX 10007
int queue[MAX];
int rear = -1;
int front = -1;
void insert(int item);
int del();
int peek();
int isEmpty();
int isFull();
void display();

int main(){
int choice,item;
    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display Front element\n");
        printf("4.Display all\n");
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
       printf("Full Queue!\n");
       return;
   }
   if(front == -1)
    front =0;
   queue[++rear]= item;
}

int del(){
  if(isEmpty()){
      printf("Empty Queue!\n");
      exit(1);
  }
  int item = queue[front];
  front++;
  return item;
}

int peek(){
    if(isEmpty()){
        printf("Empty Queue!\n");
        exit(1);
    }
    return queue[rear];
}

int isEmpty(){
    if(front == -1 || front == rear+1)
    return 1;
    else
    return 0;
}
int isFull(){
    if(rear == MAX-1)   
    return 1;
    else
    return 0;
}
void display(){
    if(isEmpty()){
        printf("Empty Queue!\n");
        return;
    }
    int i;
    printf("Queue contents: \n");
    for(i=front ;i<=rear ;i++)
     printf("%d\n",queue[i]);
}