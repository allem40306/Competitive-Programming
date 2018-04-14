#include <bits/stdc++.h>
using namespace std;
const int N=5005;
#define eps 1e-6
int n;
double w;
struct Node{
    int h,L,R;
    bool operator <(const Node&b)const{
        return h<b.h;
    }
}a[N];

int judge(int x){
    double L=atan2(a[0].h,a[0].R-x);
    double R=atan2(a[0].h,a[0].L-x);
    double cl,cr;
    for(int i=1;i<n;i++){
        cl=atan2(a[i].h,a[i].R-x);
        cr=atan2(a[i].h,a[i].L-x);
        if(L-cr>eps)return -1;
        if(cl-R>eps)return 1;
        L=max(L,cl);
        R=min(R,cr);
    }
    return 0;
}

bool sol(){
    double L=0,R=w,M;
    while(fabs(L-R)>eps){
        M=(L+R)/2;
        int k=judge(M);
        if(k==0)return true;
        if(k==1)L=M;
        else R=M;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>w>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].h>>a[i].L>>a[i].R;
        }
        sort(a,a+n);
        cout<<(sol()?"YES\n":"NO\n");
    }
}
