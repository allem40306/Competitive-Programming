#include <bits/stdc++.h>
#define REP(i,n) for ( int i=0; i<int(n); i++ )
using namespace std;

const int N=1010, eps=1e-8;

struct P {
    double x,y;
    void read() {
        scanf("%lf%lf",&x,&y);
    }
} p[N];

bool operator <( P a, P b ) { return tie(a.x,a.y)<tie(b.x,b.y); }
P operator +( P a, P b ) { return P{a.x+b.x,a.y+b.y}; }
P operator -( P a, P b ) { return P{a.x-b.x,a.y-b.y}; }
P operator *( double a, P b ) { return P{a*b.x,a*b.y}; }
P operator /( P a, double b ) { return P{a.x/b,a.y/b}; }
P& operator /=( P &a, double b ) { return a=a/b; }
double operator *( P a, P b ) { return a.x*b.y-a.y*b.x; }
double X( P o, P a, P b ) { return (a-o)*(b-o); }
double dot( P a, P b ) { return a.x*b.x+a.y*b.y; }
double dot( P o, P a, P b ) { return dot(a-o,b-o); }

int n;
void input() {
    scanf("%d",&n);
    REP(i,n) p[i].read();
}

P center;
void build() {
    p[n]=p[0];
    center=P{0,0};
    REP(i,n) {
        double v=p[i]*p[i+1];
        center.x+=(p[i].x+p[i+1].x)*v;
        center.y+=(p[i].y+p[i+1].y)*v;
    }
    double area=0;
    REP(i,n) area+=p[i]*p[i+1];
    area/=2;
    center/=6*area;
}

P q1[N],q2[N],q[N];
void solve() {
    sort(p,p+n);
    int m1=0,m2=0;
    REP(i,n) {
        while ( m1>=2 && X(q1[m1-2],q1[m1-1],p[i])>=0 ) m1--;
        while ( m2>=2 && X(q2[m2-2],q2[m2-1],p[i])<=0 ) m2--;
        q1[m1++]=q2[m2++]=p[i];
    }
    int m=0;
    REP(i,m1) q[m++]=q1[i];
    for ( int i=m2-2; i>=1; i-- ) q[m++]=q2[i];
    q[m]=q[0];
    int ans=0;
    REP(i,m) {
        bool good=1;
        if ( dot(q[i],center,q[i+1])<=eps ) good=0;
        if ( dot(q[i+1],center,q[i])<=eps ) good=0;
        if ( good ) ans++;
    }
    printf("%d\n",ans);
}

int main() {
    int t;
    scanf("%d",&t);
    while ( t-- ) {
        input();
        build();
        solve();
    }
    return 0;
}
