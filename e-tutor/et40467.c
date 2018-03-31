#include <stdio.h>
#include <stdlib.h>
//#define debug
typedef struct Node{
    int v;
    struct Node *nextPtr,*prePtr;
}node,*nodePtr;

void insert(nodePtr *sPtr, nodePtr *ePtr, int value);
void delete(nodePtr *sPtr, nodePtr *ePtr, int value);
void printList(nodePtr currentPtr);
void printReversedList(nodePtr currentPtr);
int o=0;
int main(){
    nodePtr sptr=NULL,eptr=NULL;
    char cmd;
    int v;
    while(scanf("%c",&cmd)&&cmd!='Q'){
        if(cmd=='I'){
            #ifdef debug
                printf("Insert\n");
            #endif // debug
            scanf("%d",&v);
            insert(&sptr,&eptr,v);
        }else if(cmd=='D'){
            #ifdef debug
                printf("Delete\n");
            #endif // debug
            scanf("%d",&v);
            if(sptr==NULL){
                if(o)printf("\n");
                o=1;
                printf("List is empty.\n");
                continue;
            }
            delete(&sptr,&eptr,v);
        }else if(cmd=='P'){
            #ifdef debug
                printf("Print\n");
            #endif // debug
            if(o)printf("\n");
            o=1;
            if(sptr==NULL){
                printf("List is empty.\n");
                continue;
            }
            printList(sptr);
            printReversedList(eptr);
        }
    }
    return 0;
}

void insert(nodePtr *sPtr, nodePtr *ePtr, int value){
    nodePtr newPtr=malloc(sizeof(node));
    newPtr->v=value;
    newPtr->nextPtr=NULL;
    newPtr->prePtr=NULL;
    nodePtr previousPtr=NULL,currentPtr=*sPtr;
    while(currentPtr!=NULL&&value>currentPtr->v){
        previousPtr=currentPtr;
        currentPtr=currentPtr->nextPtr;
    }
    if(previousPtr==NULL){
        if(currentPtr==NULL){
            *sPtr=*ePtr=newPtr;
        }else{
            newPtr->nextPtr=*sPtr;
            (*sPtr)->prePtr=newPtr;
            *sPtr=newPtr;
        }

    }else if(currentPtr==NULL){
        (*ePtr)->nextPtr=newPtr;
        newPtr->prePtr=*ePtr;
        *ePtr=newPtr;
    }else{
        previousPtr->nextPtr=newPtr;
        newPtr->prePtr=previousPtr;
        newPtr->nextPtr=currentPtr;
        currentPtr->prePtr=newPtr;
    }
    return;
}

void delete(nodePtr *sPtr, nodePtr *ePtr, int value){
    if(value==(*sPtr)->v){
        if(*sPtr==*ePtr){
            nodePtr tmpPtr=*sPtr;
            nodePtr tmpPtr2=*ePtr;
            *sPtr=*ePtr=NULL;
            free(tmpPtr);
            free(tmpPtr2);
        }else{
            nodePtr tmpPtr=*sPtr;
            *sPtr=(*sPtr)->nextPtr;
            (*sPtr)->prePtr=NULL;
            free(tmpPtr);
        }
    }else if(value==(*ePtr)->v){
        nodePtr tmpPtr=*ePtr;
        *ePtr=(*ePtr)->prePtr;
        (*ePtr)->nextPtr=NULL;
        free(tmpPtr);
    }else{
        nodePtr previousPtr=NULL,currentPtr=*sPtr;
        while(currentPtr!=NULL&&value>currentPtr->v){
            previousPtr=currentPtr;
            currentPtr=currentPtr->nextPtr;
        }
        if(currentPtr==NULL){
            if(o)printf("\n");
            o=1;
            printf("%d not found.\n",value);
            return;
        }
        nodePtr tmpPtr=currentPtr;
        currentPtr=currentPtr->nextPtr;
        currentPtr->prePtr=previousPtr;
        previousPtr->nextPtr=currentPtr;
        free(tmpPtr);
    }
    return;
}
void printList(nodePtr currentPtr){
    while(1){
        printf("%d",currentPtr->v);
        currentPtr=currentPtr->nextPtr;
        if(currentPtr==NULL)break;
        printf("->");
    }
    printf("\n");
    return;
}
void printReversedList(nodePtr currentPtr){
    while(1){
        printf("%d",currentPtr->v);
        currentPtr=currentPtr->prePtr;
        if(currentPtr==NULL)break;
        printf("->");
    }
    printf("\n");
    return;
}
