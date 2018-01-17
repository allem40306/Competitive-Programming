#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    node(){};
    node(int x,int y):x(x),y(y){}
    bool operator <(const node&b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
    bool operator ==(const node&b)const{
        return x==b.x&&y==b.y;
    }
};
int main(){
    int n,x,y;
    vector<node>a,b;
    while(cin>>n,n){
        a.clear();
        b.clear();
        for(int i=0;i<n;i++){
            cin>>x>>y;
            a.push_back(node(x,y));
            b.push_back(node(y,x));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
