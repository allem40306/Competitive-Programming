#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a+=b;
    c+=d;
    if(a==c){
        cout<<"Balanced\n";
    }else if(a>c){
        cout<<"Left\n";
    }else{
        cout<<"Right\n";
    }
}
