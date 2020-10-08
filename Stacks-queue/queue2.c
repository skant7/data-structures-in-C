#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *front = NULL;
struct node *rear = NULL;
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
    if(tmp== NULL){
        printf("Queue overflow!\n");
        return;
    }
    tmp->info = item;
    tmp->link = NULL; 
    if(front == NULL)
     front =tmp;
    else
      rear->link = tmp;
      rear = tmp;
}

int del(){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if(isEmpty()){
        printf("Empty Queue!\n");
        exit(1);
    }
    tmp = front ;
    int item = tmp->info;
    front = front->link;
    free(tmp);
    return item;
}

int peek(){
    if(isEmpty()){
        printf("Empty Queue!\n");
        exit(1);
    }
    return front->info;
}

int isEmpty(){
    if(front == NULL)
     return 1;
    else
     return 0;
}

void display(){
    if(isEmpty()){
        printf("Empty Queue!\n");
        return;
    }
    struct node *p = front;
    printf("Queue contents: \n");
    while(p!=NULL){
        printf("%d\n",p->info);
        p = p->link;
    }
}