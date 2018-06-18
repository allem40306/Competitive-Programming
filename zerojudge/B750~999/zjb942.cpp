#include <bits/stdc++.h>
using namespace std;
const int N=60005;

int main(){
    bool dp[N];
    string s;
    vector<int>v;
    int x,sum;
    long long ans;
    while(getline(cin,s)){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        stringstream ss(s);
        v.clear();
        while(ss>>x){
            v.push_back(x);
        }
        sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            for(int j=sum;j-v[i]>=0;j--){
                if(dp[j-v[i]])dp[j]=1;
            }
        }
        ans=0;
        for(int i=1;i<=sum/2;i++){
            if(dp[i]){
//                cout<<i<<' '<<sum-i<<'\n';
                ans=i*(sum-i);
            }
        }
        cout<<ans<<'\n';
    }
}
