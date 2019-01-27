#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct Line{
    int x,y;
    void in(){
        cin>>x>>y;
    }
    bool operator<(const Line&rhs)const{
        return ((y!=rhs.y)?(y<rhs.y):(x<rhs.x));
    }
}a[N];

int sol(int n){
    int ret=0,p=a[0].y;
    for(int i=1;i<n;i++){
        if(a[i].y==p)continue;
        if(a[i].x>p){
            ret++;
            p=a[i].y;
        }else{
            p++;
        }
    }
    return ret;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            a[i].in();
        }
        sort(a,a+n);
        cout<<sol(n)<<'\n';
    }
}