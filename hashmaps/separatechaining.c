/* SEPARATE CHAINING */
#include<stdio.h>
#include<stdlib.h>
#define MAX 11
struct employee{
    int empid;
    char name[20];
    int age;
};

struct Record{
    struct employee info;
    struct Record *link;
};
void display(struct Record* table[]);
void insert(struct employee emprec, struct Record* table[]);
void del(int key ,struct Record* table[]);
int search(int key, struct Record* table[]);
int hash(int key);
int main(){
    struct Record* table[MAX];
    struct employee emprec;
    for(int i=0 ;i<MAX ;i++)
     table[i] = NULL;
    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Display\n");
        int choice,key,i;
        scanf("%d",&choice);
        switch(choice){
            case 1:
             printf("Enter Employee details:- \n");
             scanf("%d%s%d",&emprec.empid,emprec.name,&emprec.age);
             insert(emprec,table);
             break;
            case 2:
             printf("Enter key to be deleted:\n");
             scanf("%d",&key);
             del(key ,table);
             break;
            case 3:
             printf("Enter Key to be searched:\n");
             scanf("%d",&key);
             i = search(key,table);
             printf("Record Found at %d index\n",i);
             break;
            case 4:
             display(table);
             break;
            default:
             exit(1);
        }
        
    }
}

void del(int key ,struct Record* table[]){
    int loc ;
    loc = search(key ,table);
    if(loc == -1){
        printf("Record Not Found.\n");
        return;
    }
    struct Record *ptr, *tmp;
    ptr  = table[loc];
    if(ptr->info.empid == key){
        table[loc] = NULL;
        free(ptr);
        printf("Record Deleted.\n");
        return;
    }
    while(ptr->link != NULL){
        if(ptr->link->info.empid == key){
        tmp = ptr->link;
        ptr->link = tmp->link;
        free(tmp);
        printf("Record Deleted.\n");
        }
        ptr = ptr->link;
    }
printf("Key not found\n");
     
}
void insert(struct employee emprec,struct Record* table[]){
    int key = emprec.empid;
    int loc = hash(key);
    if(search(key,table)!= -1){
        printf("Duplicate Keys\n");
        return;
    }
    struct Record* ptr = (struct Record*)malloc(sizeof(struct Record));
    ptr->info = emprec;
    ptr->link = table[loc];
    table[loc] =ptr;
}

int search(int key,struct Record* table[]){
    int loc = hash(key);
    struct Record* ptr = table[loc];
    while(ptr!=NULL){
        if(ptr->info.empid == key)
         return loc;
      ptr = ptr->link;
    }
 return -1;
}

int hash(int key){
    return key%MAX;
}

void display(struct Record* table[]){
    int i,j;
    struct Record* ptr;
    for(i=0 ;i< MAX ;i++){
     printf("\n[%d] :  ",i);
      if(table[i]!=NULL){
        ptr = table[i];
        while(ptr!=NULL){
            printf("%d  %s  %d\t",ptr->info.empid,ptr->info.name,ptr->info.age);
            ptr = ptr->link;
        }
    }
    printf("\n");
  }
}