#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
void display(struct node *start){
	struct node *p = start;
	while(p!=NULL){
		printf("%d ",p->info);
		p = p->link;
	}
 printf("\n\n");
}
struct node* push(struct node *start,int data){
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->info = data;
  if(start == NULL){
        start = tmp;
        tmp->link = NULL;
        return start;
  }
  if(start->info > data){
  	tmp->link = start;
  	start = tmp;
  	return start;
  }
  struct node *p= start;
  while(p->link->info < data && p->link != NULL)
  	p = p->link;
  tmp->link = p->link;
  p->link = tmp;
 return start;
}
int main(){
	struct node *start =NULL;
	int n,data;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    printf("Enter nodes: ");
    for(int i=1;i<=n; i++){
    	scanf("%d",&data);
    	start = push(start,data);
    }
    display(start);
	return 0;
}