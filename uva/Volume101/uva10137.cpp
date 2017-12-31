#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int main(){
    int n;
    double a[N],avg,ans1,ans2;
    while(cin>>n,n){
        avg=0.0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            avg+=a[i];
        }
        avg=(double)(int)((avg/n)*100+0.5)/100;
        ans1=ans2=0;
        for(int i=0;i<n;i++){
            if(a[i]>avg){
                ans1+=(a[i]-avg);
            }else{
                ans2+=(avg-a[i]);
            }
        }
        cout<<'$'<<fixed<<setprecision(2)<<min(ans1,ans2)<<'\n';
    }
}
