#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 100007
char infix[MAX];
char postfix[MAX];
long int stack[MAX];
int top = -1;
long int pop();
void push(long int );
void infix_postfix();
int priority(char c);
long int eval();
int isEmpty();
int isFull();
int white_space(char c);
int main(){
    printf("Enter infix: \n");
    scanf("%s",infix);
    infix_postfix();
    printf("Postfix form: %s \n",postfix);
    long int val = eval();
    printf("Value of expression is: %ld",val);
return 0;
}
void infix_postfix(){
    int i,p=0;
    char next,symbol;
    for(int i=0;i<strlen(infix);i++){
        symbol = infix[i];
        if(!white_space(symbol)){
            switch(symbol){
                case '(':
                push(symbol);
                break;
                case ')':
                 while((next = pop())!= '(')
                 postfix[p++] = next;
                 break;
                case '+':
                case '-':
                case '*':
                case '/':
                 while(!isEmpty() && (priority(symbol)<= priority(stack[top])))
                  postfix[p++] = pop();
                push(symbol);
                break;
                  default:
                  postfix[p++] = symbol;
            }
        }
    }
    while(!isEmpty())
     postfix[p++] = pop();
 postfix[p]= '\0';
}

int priority(char c){
    switch(c){
        case '+':
        case '-':
         return 1;
        case '*':
        case '/':
        case '%':
         return 2;
        case '(':
         return 0;
        default:
         return 0;
    }
}

void push(long int c){
    if(top == MAX-1){
        printf("Stack Overflow!\n");
        exit(1);
    }
  stack[++top] = c;     
}

long int pop(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int white_space(char c){
    if(c == BLANK || c== TAB)
        return 1;
    else
    return 0;
}

long int eval(){
    long int temp,a,b;
    for(int i=0 ;i <strlen(postfix);i++){
        if(postfix[i]<='9' && postfix[i]>= '0')
                push(postfix[i] - '0');
        else{
           a = pop();
           b = pop();
           switch(postfix[i]){
               case '+':
                temp = a+b; break;
               case '*':
                temp = a*b; break;
               case '/':
                temp = b/a; break;
               case '-':
                temp = b-a; break;
               case '%':
                temp = b%a; break;
           }
         push(temp);
        }        
    }
long int result = pop();
return result;
}


int isEmpty(){
    if(top == -1){
        return 1;
    }
    else
     return 0;
}   