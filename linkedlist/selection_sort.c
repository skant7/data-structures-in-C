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
struct node *sort(struct node *start){
	struct node *p , *q ,*r, *s ,*tmp;
	for(r = p = start; p->link!=NULL; r=p,p=p->link){
		for(s = q= p->link ;q!= NULL; s=q,q=q->link){
			if(p->info > q->info){
					tmp = p->link;
					p->link = q->link;
					q->link = tmp;
					if(p!=start)
						r->link = q;
					s->link = p;
					if(p == start)
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
	start = sort(start);
	display(start);
	return 0;
}