#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        if(n==1){
            cout<<"1\n";
            continue;
        }
        for(int i=9;i>1;i--){
            while(n%i==0){
                v.push_back(i);
                n/=i;
            }
        }
        if(n==1){
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                cout<<v[i];
            }
            cout<<'\n';
        }else{
            cout<<"-1\n";
        }
    }
}
