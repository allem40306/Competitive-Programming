#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,ans1[N],ans2[N],ans3[N],a,b,c;
void bulid(){
    memset(ans1,1,sizeof(ans1));
    memset(ans2,0,sizeof(ans2));
    memset(ans3,0,sizeof(ans3));
    for(int i=1;i<1000;i++){
        for(int j=i+1;;j+=2){
            if(__gcd(i,j)!=1)continue;
            a=j*j-i*i;
            b=2*i*j;
            c=j*j+i*i;
            if(c>N)break;
            ans2[c]+=1;
            for(int k=1;k*c<=N;k++){
                ans1[k*a]=min(k*c,ans1[k*a]);
                ans1[k*b]=min(k*c,ans1[k*b]);
                ans1[k*c]=min(k*c,ans1[k*c]);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(ans1[i]<=N){
            ans3[ans1[i]]++;
        }
    }
    for(int i=1;i<N;i++){
        ans2[i]+=ans2[i-1];
        ans3[i]+=ans3[i-1];
    }
}

int main(){
    bulid();
    while(cin>>n){
        cout<<ans2[n]<<' '<<n-ans3[n]<<'\n';
    }
}