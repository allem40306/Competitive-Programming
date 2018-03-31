#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],pre[N],b[N],ai,bi;

void print_lis(int v){
    if(pre[v])print_lis(pre[v]);
    cout<<a[v]<<'\n';
}

int bs(int L,int R,int v){
    int M;
    while(L<R){
        M=(L+R)>>1;
        if(a[b[M]]<v){
            L=M+1;
        }else{
            R=M;
        }
    }
    return R;
}

int main(){
    int id;
    for(ai=0;cin>>a[++ai];);
    pre[1]=0; b[bi=1]=1;
    for(int i=2;i<=ai;i++){
        if(a[i]>a[b[bi]]){
            b[++bi]=i;
            pre[i]=b[bi-1];
        }else{
            id=bs(1,bi,a[i]);
            b[id]=i;
            pre[i]=b[id-1];
        }
    }
    cout<<bi<<"\n-\n";
    print_lis(b[bi]);
}
