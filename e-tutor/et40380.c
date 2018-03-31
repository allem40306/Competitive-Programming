#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **twod(int n){
    char **arr;
    arr=(char **)calloc(n,sizeof(char *));
    for(int i=0;i<n;i++){
        arr[i]=(char *)calloc(81,sizeof(char));
    }
    return arr;
}

int cmp(const void *a,const void *b){
    int dsz=strlen(*(char **)a)-strlen(*(char **)b);
    if(dsz)return dsz;
    return strcmp(*(char **)a,*(char **)b);
}

int main(){
    int n;
    scanf("%d\n",&n);
    char **s=twod(n);
    for(int i=0;i<n;i++){
        gets(s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",s[i]);
        free(s[i]);
    }
    free(s);
}
