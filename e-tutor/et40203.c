#include <stdio.h>
#include <stdlib.h>

double *make_arr(int n){
    double *arr;
    arr=(double *)malloc(n*sizeof(double));
}

int cmp(const void * a,const void * b){
    double x=*(double *)a,y=*(double *)b;
    if(x<y)return -1;
    if(x>y)return 1;
    return 0;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        double *arr=make_arr(n);
        for(int i=0;i<n;i++){
            scanf("%lf",&arr[i]);
        }
        qsort(arr,n,sizeof(double),cmp);
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%.3lf",arr[i]);
        }
        printf("\n");
        free(arr);
    }
}
