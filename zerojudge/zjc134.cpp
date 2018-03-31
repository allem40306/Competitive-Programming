#include <bits/stdc++.h>
using namespace std;
const int N=100;
int main(){
    int t,n,sum,a[N],i,ai,r;
    bool b=0;
    cin>>t;
    while(t--){
        cin>>n;
        ai=sum=0;
        for(i=2;sum+i<=n;i++){
//            cout<<sum<<' '<<n<<'\n';
            a[ai]=i;
            ai++;
            sum+=i;
        }
        r=n-sum;
        while(r>0){
            for(i=ai-1;i>=0&&r>0;i--){
                a[i]++;
                r--;
            }
        }
        if(b)cout<<'\n';
        b=1;
        for(i=0;i<ai;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }
}
