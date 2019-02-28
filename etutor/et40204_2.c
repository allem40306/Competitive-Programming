#include <stdio.h>
#include <stdlib.h>
typedef struct List{
    char ch;
    struct List *nextptr;
}list;

int main(){
    int n;
    list* list1=(list*)malloc(sizeof(list));
    list* list2=(list*)malloc(sizeof(list));
    list* curPtr=(list*)malloc(sizeof(list));
    scanf("%d",&n);
    list1->nextptr=NULL;
    for(int i=0;i<n;i++){
        list* a=(list*)malloc(sizeof(list));
        for(curPtr=list1;curPtr->nextptr!=NULL;curPtr=curPtr->nextptr);
        a->ch=rand()%26+'A';
        curPtr->nextptr=a;
    }
}
