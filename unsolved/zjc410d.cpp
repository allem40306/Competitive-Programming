#include <bits/stdc++.h>
using namespace std;
struct node{
    int k,j;
    node(){};
    node(int k,int j):k(k),j(j){}
    bool operator <(const node& b)const{
        return k<b.k;
    }
};
int main(){
    int n,k;
    vector<node>a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(node(k,0));
    }
    for(int i=0;i<n;i++){
        cin>>a[i].j;
    }
    sort(a.begin(),a.end());
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(a[i].j);
        ans=max(ans,int(pq.size()));
        while(!pq.empty()&&pq.top()<=a[i].k){
            pq.pop();
        }
    }
    cout<<ans<<'\n';
}
