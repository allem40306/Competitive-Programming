#include <bits/stdc++.h>
using namespace std;

bool ok(double &x,double &y,double a){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if((x-i*a)*(x-i*a)+(y-j*a)*(y-j*a)>a*a)return 0;
        }
    }
    return 1;
}

int main(){
    int n,m;
    double a,x,y;
    while(cin>>n>>a,n||a){
        m=0;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(ok(x,y,a))m++;
        }
        cout<<fixed<<setprecision(5)<<a*a*(double)m/(double)n<<'\n';
    }
}
