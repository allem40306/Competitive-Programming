#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int>v;
map<int,int>ma;

bool is_B2(){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(ma.find(v[i]+v[j])!=ma.end()){
                return 0;
            }
            ma[v[i]+v[j]]=1;
        }
    }
    return 1;
}

int main(){
    int ti=1;
    while(cin>>n){
        v.clear();
        ma.clear();
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        cout<<"Case #"<<ti++<<':';
        if(is_B2()){
            cout<<" It is a B2-Sequence.\n\n";
        }else{
            cout<<" It is not a B2-Sequence.\n\n";
        }
    }
}
