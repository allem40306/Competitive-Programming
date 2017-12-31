#include <bits/stdc++.h>
using namespace std;

struct node{
    long long int n,c;
    node(){}
    node(long long int n,long long int c):n(n),c(c){}
    bool operator <(const node& b)const{
        return n>b.n;
    }
};

int main(){
    long long int n,x,ans,cc;
    priority_queue<node>pq;
    cin>>n;
    for(int ni=0;ni<n;ni++){
        ans=0;
        cc=1;
        cin>>x;
//        if(!pq.empty())
//            cout<<ni<<' '<<pq.top().n<<' '<<pq.top().c<<'\n';
        while(!pq.empty()&&pq.top().n<=x){
            ans+=(x-pq.top().n)*pq.top().c;
            cc+=pq.top().c;
            pq.pop();
        }
        if(ni)cout<<' ';
        cout<<ans;
        pq.push(node(x,cc));
    }
    cout<<'\n';
}
