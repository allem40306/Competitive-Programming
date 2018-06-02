#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL calc(LL n){
    int len=0;
    do{
        len++;
        n=n%2?3*n+1:n/2;
    }while(n!=1);
    return len;
}

int main(){
    LL a,b,ans,ansL,len;
    while(cin>>a>>b,a||b){
        if(a>b)swap(a,b);
        ansL=0;
        for(LL i=a;i<=b;i++){
            len=calc(i);
            if(len>ansL){
                ansL=len;
                ans=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,ans,ansL);
    }

}
