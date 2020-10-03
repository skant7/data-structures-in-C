#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node * link;
};
struct node *top = NULL;
void push(int item);
int pop();
int peek();
int isEmpty();
void display();
int main(){
    int choice,item;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display all\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&item);
            push(item);
            break;
            case 2:
            printf("%d popped\n",pop());
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
void push(int item){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    if(tmp == NULL){
        printf("Stack Overflow!\n");
        return;
    }
    tmp->link = top;
    top = tmp;
}

int pop(){
    struct node *tmp;
    int item;
    if(isEmpty()){
        printf("Empty stack!\n");
        exit(1);
    }
    tmp = top;
    item = top->info;
    top = top->link;
    free(tmp);
    return item;
}

int peek(){
    if(isEmpty()){
        printf("Empty Stack!\n");
        exit(1);
    }
    return top->info;
}

int isEmpty(){
    if(top == NULL)
     return 1;
    else
     return 0;
}

void display(){
    struct node *p = top;
if(isEmpty()){
    printf("Empty Stack!\n");
    return ;
}
printf("Stack contents: \n");
while(p!=NULL){
    printf("%d\n",p->info);
    p= p->link;
}

}