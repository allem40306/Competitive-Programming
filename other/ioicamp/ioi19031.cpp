#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool ok=true;
        double d[N];
        double sum=0;
        for(int i=0;i<n;i++){
            cin>>d[i];
            sum+=d[i];
            if(d[i]<0)ok=false;
        }
        sort(d,d+n);
        if(sum-d[n-1]<=d[n-1])ok=false;
        cout<<(ok?"No\n":"Yes\n");
    }
}