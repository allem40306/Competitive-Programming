#include <bits/stdc++.h>
using namespace std;

int main(){
    double x,y;
    string s;
    while(cin>>s){
        x=y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]<='9'&&s[i]>='0'){
                x=x*10+double(s[i]-'0');
            }else{
                y+=x*x;
                x=0;
            }
        }
        y+=x*x;
        cout<<fixed<<setprecision(3)<<sqrt(y)<<'\n';
    }
}
