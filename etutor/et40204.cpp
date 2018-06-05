#include <stdio.h>
#include <stdlib.h>
typedef struct List{
    char ch;
    struct List *nextptr;
}List,*Listptr;

Listptr concatelist(Listptr list1,Listptr list2);
void printlist(List* list);

int main(){
    int n;
    Listptr list1=(Listptr)malloc(sizeof(List));
    Listptr list2=(Listptr)malloc(sizeof(List));
    Listptr curPtr=(Listptr)malloc(sizeof(List));
    list1->nextptr=NULL;
    list2->nextptr=NULL;
    scanf("%d",&n);
    srand(n);
    for(int i=0;i<5;i++){
         Listptr a=(Listptr)malloc(sizeof(List));
         a->ch=rand()%26+'A';
         a->nextptr=NULL;
         for(curPtr=list1;curPtr->nextptr!=NULL;curPtr=curPtr->nextptr);
         curPtr->nextptr=a;
         curPtr->nextptr->nextptr=NULL;
    }
    for(int i=0;i<5;i++){
         Listptr a=(Listptr)malloc(sizeof(List));
         a->ch=rand()%26+'a';
         a->nextptr=NULL;
         for(curPtr=list2;curPtr->nextptr!=NULL;curPtr=curPtr->nextptr);
         curPtr->nextptr=a;
    }
    printlist(list1);
    printlist(list2);
    printlist(concatelist(list1,list2));
    return 0;
}

void printlist(List* list){
    int o=0;
    for(;;list=list->nextptr){
        if(list->nextptr==NULL)break;
//        printf("%c %d %c %d ",list->ch,list->nextptr,list->nextptr->ch,list->nextptr->nextptr);
        if(o)printf(" ");
        o=1;
        printf("%c",list->nextptr->ch);
    }
    printf("\n");
}

Listptr concatelist(Listptr list1,Listptr list2){
    Listptr curPtr=(Listptr)malloc(sizeof(List));
    for(curPtr=list1;curPtr->nextptr!=NULL;curPtr=curPtr->nextptr);
    curPtr->nextptr=list2->nextptr;
    return list1;
}
