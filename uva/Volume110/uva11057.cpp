#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans,t;
    vector<int>v;
    set<int>st;
    while(cin>>n){
        v.resize(n);
        st.clear();
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cin>>t;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(st.count(t-v[i])){
                ans=v[i];
                break;
            }
            st.insert(v[i]);
        }
        cout<<"Peter should buy books whose prices are "<<t-ans<<" and "<<ans<<".\n\n";
    }
}
