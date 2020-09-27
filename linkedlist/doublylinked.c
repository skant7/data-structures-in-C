#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* prev;
    struct node* next;
};
struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
int main(){ 
    struct node *start = NULL;
    int choice,data,item;
    while(1){
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty\n");
        printf("4.Add at beginnig\n");
        printf("5.Add at end\n");
        printf("6.Add after\n");
        printf("7.Add before\n");
        printf("8.Delete\n");
        printf("9.Reverse\n");
        printf("10.Quit\n");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                    start = create_list(start);
                    break;
                case 2:
                    display(start);
                    break;
                case 3:
                    printf("Enter element to be inserted: ");
                    scanf("%d",&data);
                    start = addtoempty(start,data);
                    break;
                case 4:
                    printf("Enter data to be entered: ");
                    scanf("%d",&data);
                    start = addatbeg(start,data);
                    break;
                case 5:
                    printf("Enter data to be inserted: ");
                    scanf("%d",&data);
                    start = addatend(start,data);
                    break;
                default:
                    exit(1);
                    printf("Wrong choice!\n");

            }
        }
   return 0;          
}
void display(struct node *start){
    struct node *p;
    if(start == NULL){
        printf("Empty List!\n");
        return; 
    }
    p = start;
    while(p!=NULL){
        printf("%d ",p->info);
        p = p->next;
    }
  printf("\n");
}
struct node *addtoempty(struct node *start,int data){
 struct node *tmp= (struct node*)malloc(sizeof(struct node));
 tmp->info = data;
 tmp->prev=NULL;
 tmp->next=NULL;
 start=tmp;
 return start;
}
struct node *addatbeg(struct node *start,int data){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp; 
return start;
}
struct node *addatend(struct node *start, int data){
    struct node *tmp,*p;
    tmp = (struct node*)malloc(sizeof(malloc));
    tmp->info = data;
    p = start;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = tmp;
    tmp->next = NULL;
    tmp->prev = p;
    return start;
}
struct node *create_list(struct node *start){
    int i,n,data;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    start = NULL;
    if(n==0){
        return start;
    }
    printf("Enter elements of list: ");
    scanf("%d",&data);
    start = addtoempty(start ,data);
    for(i=2 ; i<=n ; i++){
        scanf("%d",&data);
        start = addatend(start,data);
    }
 return start;
}