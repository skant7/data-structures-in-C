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
                    printf("Enter data to be inserted: ");
                    scanf("%d",&data);
                    start = addatbeg(start,data);
                    break;
                case 5:
                    printf("Enter data to be inserted: ");
                    scanf("%d",&data);
                    start = addatend(start,data);
                    break;
                case 6:
                    printf("Enter data to be inserted: ");
                    scanf("%d",&data);
                    printf("Enter item after which to insert: ");
                    scanf("%d",&item);
                    start = addafter(start,data,item);
                    break;
                case 7:
                    printf("Enter data to be inserted: ");
                    scanf("%d",&data);
                    printf("Enter item before which to insert: ");
                    scanf("%d",&item);
                    start = addbefore(start,data,item);
                    break;
                case 8:
                    printf("Enter data to be deleted: ");
                    scanf("%d",&item);
                    start = del(start,item);
                    break;
                case 9:
                    start = reverse(start);
                    break;
                case 10:
                    exit(1);
                    break;
                default:
                    exit(1);
                    printf("Wrong choice!\n");

            }
        }
   return 0;          
}
struct node *reverse(struct node *start){
    struct node *p1,*p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while(p2!=NULL){
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
 start = p1;
 return start;
}
struct node *del(struct node *start ,int item){
    struct node *tmp;
    if(start == NULL){
        printf("Empty List!\n");
        return start;
    }
    if(start ->next == NULL){               //Deletion of only node
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
    }
    if(start->info == item){                //Deletion of first element
         tmp = start;               
         start = start ->next;
         start->next->prev = NULL;
         free(tmp);
         return start;
    }
    tmp = start;
    while(tmp->next != NULL){               //Deletion in between
        if(tmp->info == item){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }
    if(tmp->info == item){                  //Deletion at last
        tmp->prev->next = NULL;
        free(tmp);
        return start;
    }
  printf("Element not found!\n");
  return start;
}
struct node *addbefore(struct node *start,int data,int item){
    struct node *tmp,*q;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL){
        printf("List is empty!\n");
        return start;
    }
    if(start->info ==item){
        tmp->next = start;
        tmp->prev=NULL;
        start->prev=tmp;
        start=tmp;
        return start;
    }
    q = start;
    while(q!=NULL){
        if(q->info == item){
            tmp->next=q;
            tmp->prev= q->prev;
            q->prev->next = tmp;
            q->prev = tmp;
            return start;
        }
        q= q->next;
    }
 printf("Element not found!\n");
 return start;
}
struct node *addafter(struct node *start,int data,int item){
  struct node *tmp,*p;
  tmp = (struct node *)malloc(sizeof(struct node));
  tmp ->info= data;
  p= start;
  while(p->next!=NULL){
      if(p->info == item){
           tmp->prev = p;
           tmp->next=p->next;
           if(p->next!=NULL)
                p->next->prev=tmp;
           p->next = tmp;
           return start;
      }
    p= p->next;
  }
 printf("Element not found!\n");
 return start;
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