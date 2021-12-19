#include <stdio.h>
#include <stdlib.h>

int ** make_arr(int n){
    int **a=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        a[i]=(int *)malloc(n*sizeof(int *));
    }
    return a;
}

int main(){
    int n,o=0;
    while(scanf("%d",&n)!=EOF){
        if(o)printf("\n");
        o=1;
        if(n%2==0){
            printf("It is not an odd number.\n");
            continue;
        }
        int **a=make_arr(n);
        int xx=n-1,yy=n/2,nn=1;
        for(int i=0;i<n;i++){
            if(i){
                xx=(xx-1+n)%n;
            }
            for(int j=0;j<n;j++){
                if(j){
                    xx=(xx+1)%n;
                    yy=(yy+1)%n;
                }
                a[xx][yy]=nn++;
            }
        }
        printf("%d\n",(1+n*n)*n/2);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%5d",a[i][j]);
            }
            printf("\n");
            free(a[i]);
        }
        free(a);
    }
}
