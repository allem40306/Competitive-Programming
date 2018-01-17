#include <bits/stdc++.h>
using namespace std;
const int N=405;
int m,n,a[N],num[N],c[N];

bool check(int x){
    int tmp=0,v;
    memset(c,0,sizeof(c));
    for(int i=m;i;i--){
        tmp+=a[i]*x;
        v=tmp%n;
        if(++c[v]>num[v])return false;
        tmp/=n;
    }
    return (tmp==0);
}

bool sol(){
    for(int i=1;i<n;i++){
        memset(num,0,sizeof(num));
        for(int j=1;j<=m;j++){
            a[j]=i*j%n;
            num[a[j]]++;
        }
        swap(a[1],a[m]);
        sort(a+1,a+m);
        bool ok;
        do{
            if(a[1]==0)continue;
            ok=true;
            for(int j=2;j<=m;j++){
                if(check(j))continue;
                ok=false;
                break;
            }
            if(ok)return true;
        }while(next_permutation(a+1,a+m));
    }
    return false;
}

int main(){
    while(cin>>m>>n,m||n){
        if(sol()){
            for(int i=1;i<=m;i++){
                if(i>1)cout<<' ';
                cout<<a[i];
            }
            cout<<'\n';
        }else{
            cout<<"Not found.\n";
        }
    }
}
