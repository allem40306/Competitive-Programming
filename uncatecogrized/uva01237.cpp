#include <bits/stdc++.h>
using namespace std;
const int N=10005;
struct Data{
    string name;
    int L,H;
}a[N];
int t,d;

void sol(int p){
    int ans=-1;
    for(int i=0;i<d;i++){
        if(a[i].L<=p&&p<=a[i].H){
            if(ans==-1){
                ans=i;
            }else{
                ans=-1;
                break;
            }
        }
    }
    if(ans==-1){
        cout<<"UNDETERMINED"<<'\n';
    }else{
        cout<<a[ans].name<<'\n';
    }
}

int main(){
    int q,p;
    cin>>t;
    for(int ti=0;ti<t;ti++){
        if(ti)cout<<'\n';
        cin>>d;
        for(int i=0;i<d;i++){
            cin>>a[i].name>>a[i].L>>a[i].H;
        }
        cin>>q;
        while(q--){
            cin>>p;
            sol(p);
        }
    }
}
