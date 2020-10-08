/* Implementation of queue using circular linked list */
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *rear  = NULL;
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
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("Queue Overflow!\n");
        return;
    }
    tmp->info = item;
    if(isEmpty()){
       rear = tmp;
       tmp->link = rear;
    }
    else{
            tmp->link = rear->link;
            rear->link = tmp;
            rear = tmp;
    }
}

int del(){
    struct node *tmp;
    if(isEmpty()){
        printf("Empty Queue!\n");
        exit(1);
    }
    tmp = rear->link;
    int item = rear->link->info;
    rear->link = rear->link->link;
    free(tmp);
    return item;
}

int peek(){
    if(isEmpty()){
        printf("Empty Queue!\n");
        exit(1);
    }
    return rear->link->info;
}

int isEmpty(){
    if(rear== NULL)
     return 1;
    else
     return 0;
}

void display(){
    struct node *p = rear->link;
    if(rear == NULL){
        printf("Empty Queue!\n");
        return;
    }
    do{
      printf("%d\n",p->info);
      p = p->link;
    }while(p!=rear->link);
  
}