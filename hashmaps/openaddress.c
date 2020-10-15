#include<stdio.h>
#include<stdlib.h>
#define MAX 100
enum type_of_record{EMPTY,DELETED,OCCUPIED};
struct employee{
    int empid;
    char name[20];
    int age;
};
struct Record{
    struct employee info;
    enum type_of_record status;
};
void insert(struct employee emprec, struct Record table[]);
int search(int key , struct Record table[]);
void delete(int key ,struct Record table[]);
void display(struct Record table[]);
int hash(int key);

int main(){
struct Record table[MAX];
struct employee emprec;
for(int i=0 ;i<MAX ;i++)
 table[i].status = EMPTY;


while(1){
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Search\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    int choice,key,i;
    scanf("%d" ,&choice);
    switch(choice){
        case 1:
         printf("Enter Employee Details(empid,name,age):-\n");
         scanf("%d%s%d",&emprec.empid,emprec.name,&emprec.age);
         insert(emprec,table);
         break;
        case 2:
         printf("Enter key to be deleted:-\n");
         scanf("%d",&key);
         delete(key,table);
         break;
        case 3:
         printf("Enter key to be searched:-\n");
         scanf("%d",&key);
         i = search(key,table);
         if(i== -1)
          printf("Record Not found!\n");
         else
          printf("Record Found at index %d\n",i);
          break;
        case 4:
         display(table);
         break;
        case 5:
         exit(1);
        default:
         exit(1);
    }

    }
return 0;
}


int search(int key,struct Record table[]){
  int loc,h,i;
  h = hash(key);
  loc = h;

  for(int i=1 ;i!= MAX -1;i++){
      if(table[loc].status == EMPTY)
       return -1;
      if(table[loc].info.empid  == key)
       return loc;
      loc = (h+i)%MAX;
  }
  return -1;
}

void insert(struct employee emprec,struct Record table[]){
    int key,loc,h;
    key = emprec.empid;
    loc = hash(key);
    h = loc;
    for(int i=1 ;i!=MAX-1 ;i++){
        if(table[loc].status == EMPTY || table[loc].status == DELETED){
           table[loc].info = emprec;
           table[loc].status = OCCUPIED;
           printf("Record Inserted\n\n");
           return;
    }
     if(table[loc].info.empid == key){
         printf("Duplicate Keys\n");
         return;
     }
        loc = (h+i)%MAX;
    }
  printf("Table Overflow!\n");
}

void display(struct Record table[]){
    int i;
    for(int i=0 ;i<MAX ;i++){
        printf("[%d]  :  ", i);
        if(table[i].status == OCCUPIED){
            printf("Occupied: %d  %s %d\n",table[i].info.empid,table[i].info.name,table[i].info.age);
        }
        else if(table[i].status == DELETED)
          printf("Deleted\n");
        else
          printf("Empty\n");
    }
}

void delete(int key , struct Record table[]){
    int loc,h;
    loc = search(key , table);
    if(loc == -1)
      printf("Record Not Found!\n");
    else
      table[loc].status = DELETED;
}

int hash(int key){
    return key%MAX;
}