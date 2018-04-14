#include <bits/stdc++.h>
using namespace std;
const int N=10;
int n,p[N];
double a[N],b[N];
//#define debug
bool ok(double d){
    double x=a[p[0]];
    for(int i=1;i<n;i++){
        #ifdef debug
            printf("%f:%f->%f\n",d,x+d,b[p[i]]);
        #endif // debug
        if(x+d>b[p[i]])return 0;
        x=max(x+d,a[p[i]]);
    }
    return 1;
}

double sol(){
    double L=0,R=1440*60,M;
    while(fabs(L-R)>=1e-3){
        #ifdef debug
            printf("%f %f\n",L,R);
        #endif // debug
        M=(L+R)/2;
        if(ok(M)){
            L=M;
        }else{
            R=M;
        }
    }
    return L;
}

int main(){
    int ti=1;
    double ans;
    while(cin>>n,n){
        for(int i=0;i<n;i++){
            p[i]=i;
            cin>>a[i]>>b[i];
            a[i]*=60;
            b[i]*=60;
        }
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        ans=0;
        do{
            ans=max(ans,sol());
        }while(next_permutation(p,p+n));
        printf("Case %d: %d:%.2d\n",ti++,(int)round(ans)/60,(int)round(ans)%60);
    }
    return 0;
}
