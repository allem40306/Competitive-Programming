#include <bits/stdc++.h>
using namespace std;
const int N=10005;
struct Data{
    double L,R;
    bool operator<(const Data&rhs)const{
        return L<rhs.L;
    }
}a[N];
int main(){
    int n,l;
    double w;
    while(cin>>n>>l>>w){
        int tot=0;
        double r,p;
        for(int i=0;i<n;i++){
            cin>>p>>r;
            if(r<=w/2)continue;
            double d=sqrt(r*r-(w*w)/4);
            a[tot].L=p-d;
            a[tot].R=p+d;
            // cout<<a[tot].L<<' '<<a[tot].R<<'\n';
            tot++;
        }
        sort(a,a+tot);
        if(a[0].L>0){
            cout<<"-1\n";
            continue;
        }
        bool ok=false;
        int i=0,ans=0;
        double L=0,R=0;
        while(i<tot){
            int j=i;
            while(j<tot&&a[j].L<=L){
                R=max(R,a[j].R);
                j++;
            }
            if(i==j)break;
            ans++;
            L=R;
            i=j;
            if(L>=l){
                ok=true;
                break;
            }
        }
        cout<<(ok?ans:-1)<<'\n';
    }
}