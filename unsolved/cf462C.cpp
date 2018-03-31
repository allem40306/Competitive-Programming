#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int main(){
    int n,c=0,x;
    vector<int>v;
    cin>>n>>x;
    if(x==1)c=-1;
    else c=1;
    for(int i=1;i<n;i++){
        cin>>x;
        if(x==1){
            if(c>0){
                v.push_back(c);
                c=-1;
            }else{
                c-=1;
            }
        }else{
            if(c<0){
                v.push_back(c);
                c=1;
            }else{
                c+=1;
            }
        }
    }
    v.push_back(c);
    v.push_back(0);
    v.push_back(0);
    int ans=0;
    if(v[0]>0){
        ans=v[0]-v[1]+v[2];
    }
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size()-1;j++){
            if(v[i]<0&&v[j]>0){
                ans=max(ans,-v[i]+v[j]-v[j+1]+v[j+2]);
            }
        }
    }
    cout<<ans<<'\n';

}
