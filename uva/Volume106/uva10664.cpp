#include <bits/stdc++.h>
using namespace std;
const int N=25;
//#define debug
int main(){
    int t,a[N],ai,x;
    bitset<N>dp;
    string s;
    cin>>t>>ws;
    while(t--){
        getline(cin,s);
        stringstream ss(s);
        ai=0;
        while(ss>>x){
            a[ai++]=x;
        }
        int sum=0;
        dp.reset();
        for(int i=0;i<ai;i++){
            sum+=a[i];
            for(int j=sum;j-a[i]>=0;j--){
                if(j-a[i]==0||dp[j-a[i]])dp[j]=1;
            }
        }
        #ifdef debug
            printf("!%d\n",sum);
        #endif // debug
        if(sum%2||!dp[sum/2]){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}
