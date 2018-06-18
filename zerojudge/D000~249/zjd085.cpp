#include <bits/stdc++.h>
using namespace std;
const int N=100000;
vector<int>v;
bitset<N>bi;

void prime(){
    v.clear();
    bi.reset();
    for(int i=2;i<N;i++){
        if(!bi[i]){
            v.push_back(i);
        }
        for(int j=0;j<v.size()&&i*v[j]<N;j++){
            bi[i*v[j]]=1;
            if(i%v[j]==0){
                break;
            }
        }
    }
}


int main(){
    prime();
    int n,a,b;
    bool m;
    while(cin>>n){
        if(n==0){
            cout<<n<<'\n';
            continue;
        }
        a=1;
        if(n<0){
            m=1;
        }else{
            m=0;
        }
        n=abs(n);
        for(int i=0;v[i]*v[i]<=n;i++){
            while(n%(v[i]*v[i])==0){
                a*=v[i];
                n/=v[i]*v[i];
            }
        }
        if(a!=1){
            cout<<a;
        }
        if(n!=1){
            cout<<"_/"<<n;
        }
        if(m){
            cout<<'i';
        }
        cout<<'\n';
    }
}
