#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL findt(LL a,LL b,LL n){
//    cout<<a<<' '<<b<<' '<<n<<'\n';
    LL t;
    if(a%(n+1))return -1;
    while((a%(n+1)==0)&&(b%n==0)){
        a/=n+1;
        b/=n;
        t++;
    }
    if(a==1&&b==1)return t;
    return -1;
}

int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
    LL h,hh,w,t;
    while(cin>>h>>w,h||w){
        if(h==1&&w==1){
            cout<<"0 1\n";
            continue;
        }else if(w==1){
            t=0;
            hh=h;
            while(hh%2==0){
                t++;
                hh/=2;
            }
            cout<<t<<' '<<2*h-w<<'\n';
        }else{
            for(LL i=1;i<=sqrt(h);i++){
                if(w%i)continue;
                t=findt(h,w,i);
                if(t>0){
                    if(i==1){
                        cout<<t<<' '<<(i+1)*h-w*i<<'\n';
                    }else{
                        cout<<(w-1)/(i-1)<<' '<<(i+1)*h-w*i<<'\n';
                    }
                    break;
                }
                t=findt(h,w,w/i);
                if(t>0){
                    cout<<(w-1)/(w/i-1)<<' '<<(w/i+1)*h-w*(w/i)<<'\n';
                    break;
                }
            }
        }
    }
}
