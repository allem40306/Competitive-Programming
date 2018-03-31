#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int main(){
    int n,a[N],sum=0;
    bitset<4000005>b;
    b.reset();
    cin>>n;
    b[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        for(int j=sum;j-a[i]>=0;j--){
            if(b[j-a[i]]){
                b[j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<4000005;i++){
        if(b[i]&&abs(sum/2-i)<=abs(sum/2-ans)){
            ans=i;
        }
    }
    cout<<ans<<'\n';
}
