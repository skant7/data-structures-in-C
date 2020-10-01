#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *display(struct node *start){
	struct node *p = start;
	while(p!=NULL){
		printf("%d ",p->info);
		p = p->link;
	}
}
struct node *b_sort(struct node *start){
    struct node *tmp,*r,*end,*p,*q;
    for(end = NULL ;end != start->link;end=q){
    	for(r=p=start;p->link != end ; r=p,p=p->link){
    		q = p->link;
    		if(p->info > q->info){
    			p->link = q->link;
    			q->link = p;
    		   if(p!=start)
    		   	 r->link = q;
    		   	else
    		   		start = q;
    		   	tmp = p;
    		   	p = q;
    		   	q = tmp;
    		}
    	}
    }
   return start;
}
struct node *push(struct node *start ,int data){
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	if(start == NULL){
		start = tmp;
		tmp->link = NULL;
		return start;
	}
	struct node *p = start;
	while(p->link != NULL)
		p = p->link;
	tmp->link = p->link;
	p->link = tmp;
return start;
}
int main(){
	struct node *start= NULL;
	int n,data;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data);
		start = push(start,data);
	}
	start = b_sort(start);
	display(start);
	return 0;
}