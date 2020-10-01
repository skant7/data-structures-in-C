#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *push(struct node *start,int data){
	struct node *tmp ,*p=start;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	if(start == NULL){
		start = tmp;
		tmp = NULL;
		return start;
	}
  while(p->link != NULL)
  	p=p->link;
  tmp->link = p->link;
  p->link =tmp;
  return start;
}
struct node *sort_push(struct node *start ,int data){
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
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
	struct node *p = start;
	while(p->link->info < data && p->link != NULL)
		p = p->link;
	tmp->link = p->link;
	p->link = tmp;
return start;
}
struct node *merge(struct node* p1, struct node *p2){
	struct node *start3 = NULL;
	while(p1!=NULL && p2!= NULL){
		if(p1->info < p2->info){
			start3 = push(start3,p1->info);
			p1 = p1->link;
		}
		else if(p2->info < p1->info){
			start3 = push(start3 , p2->info);
			p2 = p2->link;
		}
		else if(p2->info == p1->info){
			start3 = push(start3, p1->info);
			p1 = p1->link;
			p2 = p2->link;
		}
	}

	while(p1!=NULL){
		start3 = push(start3,p1->info);
		p1 = p1->link;
	}
	while(p2!=NULL){
		start3 = push(start3 ,p2->info);
		p2 = p2->link;
	}
return start3;
}

struct node *display(struct node *start){
	struct node *p = start;
	while(p!=NULL){
		printf("%d ",p->info);
		p = p->link;
	}
}
int main(){
	struct node *start1= NULL, *start2 = NULL,*start;
	int n,data;
	printf("Enter List 1 size and items: \n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data);
		start1 = sort_push(start1,data);
	}
	printf("Enter List 2 size and items: \n");
	scanf("%d",&n);
   	for(int i=1;i<=n;i++){
		scanf("%d",&data);
		start2 = sort_push(start2,data);
	}	
	start = merge(start1,start2);
	display(start);
	return 0;
}