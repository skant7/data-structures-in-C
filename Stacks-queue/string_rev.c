/* Reversing a string using stacks*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1007
char string[MAX];
void push(char c);
char pop();
int top = -1;
int main(){
    scanf("%s",string);
    for(int i=0;i<strlen(string);i++)
        push(string[i]);
    for(int i=0;i<strlen(string);i++)
      printf("%c",pop());
  return 0;
}
void push(char c){
    if(top == MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    string[++top] = c;
}
char pop(){
    if(top == -1){
        printf("Invalid pop!\n");
        exit(1);
    }
    char c = string[top];
    top--;
    return c;   
}