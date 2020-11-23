#include <stdio.h>
#include <stdlib.h>
#define MAX 10007
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *stack[MAX];
int top = -1;
struct node *insert(struct node *ptr, int ikey);
struct node *del(struct node *ptr, int data);
struct node *search(struct node *ptr, int skey);
int findmax(struct node *ptr);
int findmin(struct node *ptr);
void pre(struct node *ptr);
void in(struct node *ptr);
void post(struct node *ptr);
void nrec_pre(struct node *ptr);
void nrec_in(struct node *root);
void nrec_post(struct node *root);
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();
int main()
{
    int n, data;
    struct node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    /*pre(root);
    printf("\n");
    nrec_pre(root);
    in(root);
    printf("\n");
    nrec_in(root);
    printf("\n");*/
    post(root);
    printf("\n");
    nrec_post(root);
    return 0;
}
void pre(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->data);
    pre(ptr->lchild);
    pre(ptr->rchild);
}
void post(struct node *ptr)
{
    if (ptr == NULL)
        return;
    post(ptr->lchild);
    post(ptr->rchild);
    printf("%d ", ptr->data);
}
void in(struct node *ptr)
{
    if (ptr == NULL)
        return;
    in(ptr->lchild);
    printf("%d ", ptr->data);
    in(ptr->rchild);
}
void push_stack(struct node *item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
}

struct node *pop_stack()
{
    struct node *item;
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    item = stack[top];
    top--;
    return item;
}

struct node *insert(struct node *root, int ikey)
{
    struct node *ptr, *par, *tmp;
    par = NULL;
    ptr = root;
    while (ptr != NULL)
    {
        par = ptr;
        if (ikey < ptr->data)
            ptr = ptr->lchild;
        else if (ikey > ptr->data)
            ptr = ptr->rchild;
        else
        {
            printf("Duplicate keys found!\n");
            return root;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    tmp->data = ikey;
    if (par == NULL)
        root = tmp;
    else if (ikey < par->data)
        par->lchild = tmp;
    else
        par->rchild = tmp;
    return root;
}
int stack_empty(){
    if(top == -1)
     return 1;
    else
     return 0;
}
void nrec_pre(struct node *root)
{   
    struct node *ptr = root;
    if(ptr == NULL){
        printf("Empty Tree!\n");
        return;
    }
    push_stack(ptr);
    while(!stack_empty()){
        ptr = pop_stack();
        printf("%d ",ptr->data);
        if(ptr->rchild != NULL)
         push_stack(ptr->rchild);
        if(ptr->lchild != NULL)
         push_stack(ptr->lchild);
    }
}

void nrec_in(struct node *root){
    struct node *ptr = root;
    if(ptr == NULL){
        printf("Tree Empty!\n");
        return;
    }
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr->lchild;
        }

        while(ptr->rchild == NULL){
            printf("%d ",ptr->data);
            if(stack_empty())
                return;
            ptr = pop_stack();
        }
        printf("%d ", ptr->data);
        ptr = ptr->rchild;
    }
}
void nrec_post(struct node *root){
    struct node *ptr = root;
    if(ptr == NULL){
        printf("Empty Tree!\n");
        return;
    }
    struct node *q = root;
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr->lchild;
        }

        while(ptr->rchild == NULL || ptr->rchild == q){
            printf("%d ", ptr->data);
            q = ptr;
            if(stack_empty())
             return;
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->rchild;
    }
}
