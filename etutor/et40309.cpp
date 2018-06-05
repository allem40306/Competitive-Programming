#include <stdio.h>
#include <stdlib.h>

typedef struct Loc{
    int x,y;
}loc;

int cmp(const void *a,const void *b);

int main(){
    int n,o=0,ansp,ans;
    while(scanf("%d",&n)!=EOF){
        ansp=0; ans=-20000;
        if(o)printf("\n");
        o=1;
        loc *a=(loc *)malloc(n*sizeof(loc));
        for(int i=0;i<n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        qsort(a,n,sizeof(loc),cmp);
        for(int i=0;i<n;i++){
            if(a[i].x+a[i].y>=ans){
                ansp=i;
                ans=a[i].x+a[i].y;
            }
            printf("(%d,%d)\n",a[i].x,a[i].y);
        }
        printf("max num:%d\n",a[ansp].x+a[ansp].y);
        printf("point:(%d,%d)\n",a[ansp].x,a[ansp].y);
        free(a);
    }
}

int cmp(const void *a,const void *b){
    struct Loc *A=(Loc *)a,*B=(Loc *)b;
    if(A->x-B->x)return A->x-B->x;
    return A->y-B->y;
}
