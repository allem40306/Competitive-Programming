#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    bool o=0;
    cin>>a>>b>>c;
    a=bool(a);
    b=bool(b);
    if((a&b)==c){
        cout<<"AND\n";
        o=1;
    }
    if((a|b)==c){
        cout<<"OR\n";
        o=1;
    }
    if((a^b)==c){
        cout<<"XOR\n";
        o=1;
    }
    if(!o)cout<<"IMPOSSIBLE\n";
}
