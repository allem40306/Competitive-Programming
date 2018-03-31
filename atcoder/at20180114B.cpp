#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int main(){
    long long a[N],x=2,y=2,z,w;
    int k;
//    bool ok=1;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    for(int i=k-1;i>=0;i--){
        z=(x/a[i]+(x%a[i]!=0))*a[i];
        w=(y/a[i])*a[i];
//        cout<<z<<' '<<w<<'\n';
//        if((z<x||y<z){
//            ok=0;
//            break;
//        }
        x=z;
        y=w+a[i]-1;
//        cout<<x<<' '<<y<<'\n';
    }
    if(x<y){
        cout<<x<<' '<<y<<'\n';
    }else{
        cout<<"-1\n";
    }
}
//6 8
//4 7
//3 5
//2 3
//2 2
