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
//    freopen("11063.txt","w",stdout);
    int ti=1;
    bool f;//first
    while(cin>>n){
        f=1;
        v.clear();
        ma.clear();
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
            if((v[i]<1)||(i&&v[i]<=v[i-1])){
                f=0;
            }
        }
        cout<<"Case #"<<ti++<<':';
        if(f&&is_B2()){
            cout<<" It is a B2-Sequence.\n\n";
        }else{
            cout<<" It is not a B2-Sequence.\n\n";
        }
    }
}
