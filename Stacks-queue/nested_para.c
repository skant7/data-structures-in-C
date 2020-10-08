/*Checking Validity of nested parantheses*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1007
int stack[MAX];
int top = -1;
void push(char c);
char pop();
int check(char *);
int match(char a, char b);
int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    if(check(str))
     printf("Balanced\n");
    else
     printf("Not Balanced!\n");
return 0;
}
int check(char *str){
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='{' || str[i]=='(' || str[i]== '[')
              push(str[i]);
            else if(str[i]=='}' ||str[i]==')'||str[i]==']'){
                if(top == -1){
                    printf("Right Parenthese more than Left!\n");
                    return 0;
                }
                else{
                    char temp = pop();
                    if(!(match(str[i],temp))){
                    printf("Mismatched Parentheses!\n");
                    return 0;
                    }
                }
            }
        }
    if(top == -1)
      return 1;
    else {
        printf("Left Parentheses more than Right!\n");
        return 0;
    }
}

int match(char a , char b){
    if(a == ')' && b == '(')
     return 1;
    if(a == '}' && b == '{')
     return 1;
    if(a == ']' && b == '[')
     return 1;
 return 0;
}

void push(char c){
    if(top == MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow!\n");
        exit(1);
    }
    char c = stack[top];
    top--;
    return c;
}