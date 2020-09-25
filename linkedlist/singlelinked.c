//Single-linked list operations//
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};
void display(struct node* start);
void count(struct node* start);
void search(struct node*, int data);
struct node* addatbeg(struct node*,int data);
struct node* addatend(struct node*,int data);
struct node* addatpos(struct node*,int data);
struct node* addbefore(struct node*,int data);
struct node* addafter(struct node*,int data);
struct node* del(struct node*,int data);
struct node* create_list(struct node*start);
void reverse(struct node*);
int main(){
struct node* start = NULL;
int choice,data,item,pos;
while(1){
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Count\n");
    printf("4.Search\n");
    printf("5.Add to empty / Add at beginning\n");
    printf("6.Add at end\n");
    printf("7.Add at after node\n");
    printf("8.Add before node\n");
    printf("9.Add at position\n");
    printf("10.Delete\n");
    printf("11.Reverse\n");
    printf("12.Quit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
         start = create_list(start);
         break;
        case 2:
         display(start);
         break;
        default:
         exit(1);

    }
}

return 0;
}

struct node* create_list(struct node* start){
    int i,data,n;
    start = NULL;
    printf("Enter No. of Nodes: ");
    scanf("%d",&n);
    if(n==0)
     return start;
    printf("Enter element: ");
    scanf("%d",&data);
    start = addatbeg(start,data);
    for(int i=2; i<=n; i++){
          printf("Enter element: ");
          scanf("%d",&data);
          start = addatend(start,data);
    }
return start;
}

void display(struct node* start){
    struct node* p= start;
    if(p == NULL){
      printf("Empty list.\n");
    }
    printf("List contents: \n");
    while(p!= NULL){
        printf("%d ",p->info);
        p = p-> link;

    }
   printf("\n\n");
}