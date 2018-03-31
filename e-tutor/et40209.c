#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define debug
typedef struct Node{
    char ch;
    struct Node *next;
}node,*node_ptr;

int isPalindrome(char *string);
void push(node_ptr *top,char v);
int is_empty(node_ptr top);
char pop(node_ptr *top);

int main(){
    char *string=(char *)malloc(100*sizeof(char));
    gets(string);
    isPalindrome(string)?printf("\"%s\" is a palindrome\n",string):printf("\"%s\" is not a palindrome\n",string);
}

int isPalindrome(char *string){
    node_ptr h=NULL;
    for(int i=0;string[i];i++){
        if(!isalpha(string[i]))continue;
        push(&h,string[i]);
    }
    char cmp;
    int si=0;
    while(!is_empty(h)){
        cmp=pop(&h);
        while(!isalpha(string[si]))si++;
        if(cmp!=string[si])return 0;
        si++;
    }
    return 1;
}

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
