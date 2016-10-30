#include <iostream>
using namespace std;
#define N 100005

int main(){
    static int a[N],n,i,j,k,ans;
    while(cin>>n){
        j=1; ans=0; k=n-1; a[0]=0;
        for(i=1;i<=n;i++){cin>>a[i];a[i]+=a[i-1];}
        while(j<=n||k>=0){
            if(a[j]==a[n]-a[k]){ans++; j++; k--;}
            else if(a[j]<a[n]-a[k])j++;
            else k--;
        }
        printf("%d\n",ans);
    }    
}
