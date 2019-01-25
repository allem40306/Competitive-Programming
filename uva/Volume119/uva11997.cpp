#include <bits/stdc++.h>
using namespace std;
const int N=1000;

struct Data{
    int sum,i;
    bool operator<(const Data &rhs)const{
        return sum>rhs.sum;
    }
};

int main(){
    int n;
    int a[N],b[N];
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int ni=1;ni<n;ni++){
            for(int i=0;i<n;i++){
                cin>>b[i];
            }
            sort(b,b+n);
            priority_queue<Data>pq;
            for(int i=0;i<n;i++){
                pq.push(Data{a[i]+b[0],0});
            }
            for(int i=0;i<n;i++){
                Data tmp=pq.top(); pq.pop();
                a[i]=tmp.sum;
                if(tmp.i+1<n){
                    pq.push(Data{tmp.sum-b[tmp.i]+b[tmp.i+1],tmp.i+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }
}