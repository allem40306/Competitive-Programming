#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a=0,b=0,si;
    string s;
    while(cin>>s){
        si=0;
        for(;!a&&si<s.size();si++){
            if(!isdigit(s[si]))continue;
            while(si<s.size()&&isdigit(s[si])){
                a=a*10+int(s[si]-'0');
                si++;
            }
            break;
        }
        for(;si<s.size();si++){
            if(!isdigit(s[si]))continue;
            while(si<s.size()&&isdigit(s[si])){
                b=b*10+int(s[si]-'0');
                si++;
            }
            break;
        }
        if(a&&b)break;
    }
    cout<<a<<' '<<b<<' '<<a+b<<'\n';
}
