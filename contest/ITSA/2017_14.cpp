#include <iostream>
using namespace std;

int main(){
    int t,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if((a<=c)&&(b<=d)||(a<=d)&&(b<=c)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
