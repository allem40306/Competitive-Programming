#include <bits/stdc++.h>
using namespace std;
const int N=1005;
struct Point{
    int x,y;
    Point(){};
    Point(int x,int y):x(x),y(y){}
    bool operator <(const Point&b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
};
//#define debug
int main(){
    int t,n,mn,mx,M;
    bool ok;
    Point a[N];
    cin>>t;
    set<Point>sp;
    while(t--){
        cin>>n;
        mn=20000;
        mx=-20000;
        sp.clear();
        for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y;
            a[i].x*=2;
            mn=min(mn,a[i].x);
            mx=max(mx,a[i].x);
            sp.insert(a[i]);
        }
        ok=1;
        M=(mn+mx)>>1;
        #ifdef debug
            printf("m=%d\n",M);
        #endif // debug
        for(int i=0;i<n;i++){
            if(!sp.count(Point(2*M-a[i].x,a[i].y))){
                ok=0;
                break;
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}
