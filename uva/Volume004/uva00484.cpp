#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v,w;
    int x;
    while(cin>>x){
        if(find(v.begin(),v.end(),x)!=v.end()){
            w[find(v.begin(),v.end(),x)-v.begin()]++;
        }else{
            v.push_back(x);
            w.push_back(1);
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' '<<w[i]<<'\n';
    }
}
