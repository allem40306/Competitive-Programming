#include <stdio.h>
#include <stdlib.h>
#define debug
typedef struct Node{
    char ch;
    struct Node *next;
}node,*node_ptr;

void push(node_ptr *top,char v){
    node_ptr newptr=malloc(sizeof(node));
    newptr->ch=v;
    newptr->next= *top;
    *top=newptr;
}

char pop(node_ptr *top){
    node_ptr tmp=*top;
    *top=(*top)->next;
    char ch=tmp->ch;
    free(tmp);
    return ch;
}

int is_empty(node_ptr top){
    return top==NULL;
}

void printreverse(char *string){
    node_ptr h=NULL;
    for(int i=0;string[i];i++){
        push(&h,string[i]);
    }
    while(!is_empty(h)){
        printf("%c",pop(&h));
    }
    printf("\n");
}

int main(){
    char *string=(char *)malloc(100*sizeof(char));
    gets(string);
    printreverse(string);
}
