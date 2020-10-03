#include<stdio.h>
#include<stdlib.h>
#define MAX 1007
int stack[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
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
    if(isFull()){
        printf("Stack Overflow!\n");
        return ;
    }
    top++;
    stack[top] = item;
}

int pop(){
  int item;
  if(isEmpty()){
      printf("Stack Underflow!\n");
      exit(1);
  }
  item = stack[top];
  top--;
  return item;
}

int peek(){
    if(isEmpty()){
        printf("Empty array!\n");
        exit(1);
    }
    return stack[top];
}
int isEmpty(){
    if(top==-1)
     return 1;
    else
     return 0;
}

int isFull(){
    if(top== MAX-1)
     return 1;
    else
     return 0;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Empty Array!\n");
        return;
    }
    printf("Stack elements: \n");
    for(i= top;i>=0;i--)
     printf("%d\n",stack[i]);
    printf("\n");
}