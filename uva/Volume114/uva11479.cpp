#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long int a,b,c;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>a>>b>>c;
        if(c<a)swap(a,c);
        if(c<b)swap(b,c);
        if(b<a)swap(a,b);
        cout<<"Case "<<ti<<": ";
        if(a+b<=c||a<=0||b<=0||c<=0){
            cout<<"Invalid\n";
        }else if(a==b&&b==c){
            cout<<"Equilateral\n";
        }else if(a==b||b==c||a==b){
            cout<<"Isosceles\n";
        }else{
            cout<<"Scalene\n";
        }
    }
}
