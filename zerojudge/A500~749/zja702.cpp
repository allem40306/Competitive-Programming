#include <bits/stdc++.h>
using namespace std;
const int N=20000000;
bitset <N>b;
vector<int>v;
void prime(){
    b.reset();
    b[0]=b[1]=1;
    for(int i=2;i<N;i++){
        if(!b[i]){
//                cout<<i<<'\n';
            for(int j=i+i;j<N;j+=i){
                b[j]=1;
            }
            if(i>4&&!b[i-4]){
                v.push_back(i-4);
            }
        }
    }
}
int main(){
    int n;
    prime();
    while(cin>>n){
        cout<<"("<<v[n-1]<<", "<<v[n-1]+4<<")\n";
    }
}
