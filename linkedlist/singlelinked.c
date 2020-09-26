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
struct node* addatpos(struct node*,int data , int item);
struct node* addbefore(struct node*,int data,int item);
struct node* addafter(struct node*,int data,int item);
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
    printf("7.Add after node\n");
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
        case 3:
         count(start);
         break;
        case 4:
         printf("Enter element to be searched: ");
         scanf("%d",&data);
         search(start,data);
         break;
        case 5:
         printf("Enter element to be inserted: ");
         scanf("%d",&data);
         start = addatbeg(start,data);
         break;
        case 6:
         printf("Enter element to be inserted: ");
         scanf("%d",&data);
         start = addatend(start,data);
         break;
        case 7:
         printf("Enter item to be inserted: ");
         scanf("%d",&data);
         printf("Enter node after which to insert: ");
         scanf("%d",&item);
         start = addafter(start,data,item);
         break;
        case 8:
         printf("Enter item to be inserted: ");
         scanf("%d",&data);
         printf("Enter node before which to insert: ");
         scanf("%d",&item);
         start= addbefore(start,data,item);
         break;
        case 9:
            printf("Enter postion : ");
            scanf("%d", &pos);
            printf("Enter element to be entered: ");
            scanf("%d",&data);
            start = addatpos(start,data,pos);
            break;
        default:
         exit(1);

    }
}

return 0;
}

struct node* addatpos(struct node* start,int data ,int pos){
  struct node *tmp, *p;
  int i;
  tmp = (struct node*)malloc(sizeof(struct node));
  tmp->info = data;
  if(pos == 1){
      tmp->link = start;
      start = tmp;
      return start;
  }
  p = start;
  for(i=1 ; i<pos-1 && p!= NULL ;i++){
      p = p->link;
  }
 if(p == NULL)
  printf("Position exceeds total number of elements!\n");
 else{
     tmp -> link = p->link;
     p-> link = tmp;
 }
return start;
}
struct node* addbefore(struct node* start,int data, int item){
 struct node* tmp, *p;
 tmp = (struct node*)malloc(sizeof(struct node));
 p = start;
 while(p->link != NULL){
        if(p->link->info == item){
            tmp->info =data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
   p=p->link;
 }
return start;
}
struct node* addafter(struct node* start,int data,int item){
    struct node* p = start;
    struct node* temp = (struct node*)(malloc(sizeof(struct node)));
    temp->info = data;
    while(p!=NULL){
        if(p->info == item){
            temp->link = p->link;
            p->link = temp;
            return start;
        }
     p = p->link;
    }
 return start;
}
void count(struct node* start){
    if(start == NULL){
        printf("List is empty.\n");
        return;
    }
    struct node* p = start;
    int count=0;
    while(p!= NULL){
      p = p->link;
      count++;
    }
 printf("list consists of %d elements.\n",count);
}

void search(struct node* start,int data){
    struct node* p = start;
    int pos = 1;
    while(p != NULL){
        if(p->info==data){
           printf("element found at %d position.\n",pos);
           return;
        }
        p= p->link;
        pos++;
    }
   printf("Element not found!\n"); 
}
struct node* addatbeg(struct node* start,int data){
    struct node* temp  = (struct node *)(malloc(sizeof(struct node)));
    temp->info = data;
    temp->link = start;
    start = temp;
    return start;
}

struct node* addatend(struct node* start,int data){
    struct node* temp = (struct node *)(malloc(sizeof(struct node)));
    temp->info = data;
    struct node* p = start;
    while(p->link != NULL){
        p = p->link;
    }
   p->link = temp;
   temp->link = NULL;
return start;   
}
struct node* create_list(struct node* start){
    int i,data,n;
    start = NULL;
    printf("Enter No. of Nodes: ");
    scanf("%d",&n);
    if(n==0)
     return start;
    printf("Enter elements: ");
    scanf("%d",&data);
    start = addatbeg(start,data);
    for(int i=2; i<=n; i++){
          //printf("Enter element: ");
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
        p = p->link;

    }
   printf("\n\n");
}