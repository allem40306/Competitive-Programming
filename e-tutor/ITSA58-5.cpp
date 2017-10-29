#include <iostream>
#include <cstring>
using namespace std;
unsigned long long n,ans,sel[20],noc[20][20],step[20]={1,1};
void sol(unsigned long long s,unsigned long long x,unsigned long long y){
    //cout<<s<<' '<< x<<' '<<y<<'\n';
    //for(int i=1,j;i<=15;i++){cout<<sel[i]<<"+";}cout<<'\n';
    if(y<0)return;
    if(!x){
        if(y)return;
        unsigned long long nn=n,sum=1;
        for(int i=1,j;i<=15;i++){
            for(j=0;sel[i]&&j<sel[i];j++){
                sum*=noc[nn][i];
                nn-=i;
             }
            sum/=step[sel[i]];
        }
        //for(int i=1,j;i<=15;i++){cout<<sel[i]<<"+";}cout<<'\n';
        ans+=sum;
        return;
    }
    for(int i=s;i<=x;i++){
        sel[i]++;
        sol(i,x-i,y-1);
        sel[i]--;
    }
    return;
}

int main(){
    unsigned long long int t,m;
    char ch;
    cin>>t;
    for(int i=2;i<=15;i++){
        step[i]=i*step[i-1];
    }
    for(int i=1;i<=15;i++){
        for(int j=0;j<=i;j++){
            if(!j||i==j)noc[i][j]=1;
            else noc[i][j]=noc[i-1][j-1]+noc[i-1][j];
        }
    }
    memset(sel,0,sizeof(sel));
    for(int i=0;i!=t;i++){
            cin>>n>>ch>>m;
            if(n<m)cout<<"0\n";
            else if(n==1||m==1||n==m)cout<<"1\n";
            else{
                ans=0;
                sol(1,n,m);
                cout<<ans<<'\n';
            }
    }
} 
