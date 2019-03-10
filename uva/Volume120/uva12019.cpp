#include <bits/stdc++.h>
using namespace std;
int mdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string s[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int calc(int m,int d){
    for(int i=0;i<m;i++){
        d+=mdays[i];
    }
    return d;
}

int main(){
    int t,m,d,v;
    cin>>t;
    while(t--){
        cin>>m>>d;
        v=calc(m,d);
        cout<<s[(v+4)%7]<<'\n';
    }
}
