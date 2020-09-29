#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};
void display(struct node* last);
struct node* addatbeg(struct node*,int data);
struct node* addatend(struct node*,int data);
struct node* addtoempty(struct node*,int data);
struct node* addafter(struct node*,int data,int item);
struct node* del(struct node*,int data);
struct node* create_list(struct node*);
int main(){
struct node* last = NULL;
int choice,data,item;
while(1){
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Add to empty List.\n");
    printf("4.Add at beginning.\n");
    printf("5.Add at end\n");
    printf("6.Add after node\n");
    printf("7.Delete\n");
    printf("8.Quit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            last = create_list(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            printf("Enter element to insert: ");
            last = addtoempty(last ,data);
            break;        
        case 4:
            printf("Enter element to insert: ");
            scanf("%d",&data);
            last = addatbeg(last,data);
            break;
        case 5:
            printf("Enter element to be insert: ");
            scanf("%d",&data);
            last=addatend(last,data);
            break;
            
        case 6:
           printf("Enter element to insert: ");
           scanf("%d",&data);
           printf("Enter element after which to insert: ");
           scanf("%d",&item);
           last = addafter(last,data,item);
           break;
        case 7:
           printf("Enter item to delete: ");
           scanf("%d",&item);
           last = del(last,item);
           break;
        case 8:
         exit(1); 
        default:
         printf("Wrong Choice!\n");
         break;
    }
}
return 0;
}
struct node *del(struct node *last,int item){
     struct node *tmp;
     if(last->link ==last && last->info == item){
         tmp = last;
         last = NULL;
         free(tmp);
         return last;
     }
     tmp = last->link;
     if(tmp->info == item ){
         tmp = last->link;
         last->link = tmp->link;
         free(tmp);
         return last;
     }
    struct node* p= last->link;
    while(p->link!=last){
        if(p->link->info == item){
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
     p = p->link;
    }
    if(last->info == item){
        tmp = last;
        p->link = last->link;
        last = p;
        free(tmp);
        return last;
        
    }
    printf("Element not found!\n");
    return last;
}
struct node *addafter(struct node *last,int data,int item){
    struct node *p,*tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    p= last->link;
    do{
       if(p->info == item){
           tmp->info = data;
           tmp->link = p->link;
           p->link = tmp;
           if(p==last)
            last =tmp;
        return last;
       }
      p= p->link;
    }while(p!=last->link);
  printf("Element not present in list!.\n");
  return last;
}
void display(struct node* last){
    struct node *p;
    if(last == NULL){
        printf("Empty List!\n");
        return;
    }
    p = last->link;
    do{
        printf("%d ",p->info);
        p = p->link;
    }while(p!=last->link);
  printf("\n\n");
}
struct node *addtoempty(struct node *last,int data){
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    last = tmp;
    last->link= last;
  return last;
}
struct node *addatbeg(struct node *last,int data){
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
return last;
}
struct node *addatend(struct node *last,int data){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last ->link = tmp;    
    last = tmp;
 return last;
}
struct node *create_list(struct node *last){
 struct node *tmp;
 int n,data;
 last = NULL;
 printf("Enter size of list: ");
 scanf("%d",&n);
 if(n==0){
    return last;
 }
 printf("Enter elements of list: ");
 scanf("%d",&data);
 last = addtoempty(last ,data);
 for(int i=1 ;i<n ;i++){
     scanf("%d",&data);
     last = addatend(last,data);
 }
return last;
}