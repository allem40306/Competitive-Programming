#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,d1,d2,y1,y2;
    string m1,m2;
    char ch;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>m1>>d1>>ch>>y1;
        cin>>m2>>d2>>ch>>y2;
        if(m1=="January"||m1=="February")y1--;
        if((m2=="January"||(m2=="February"&&d2<29)))y2--;
        cout<<"Case "<<i<<": "<<((y2/4)-(y2/100)+(y2/400))-((y1/4)-(y1/100)+(y1/400))<<'\n';
    }
}
