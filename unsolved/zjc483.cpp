#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    string s;
    while(getline(cin,s)){
        if(s[s.size()-1]=='{'){
            cout<<s.substr(0,s.size()-1)<<'\n';
            t++;
            for(int i=1;i<t;i++)cout<<'\t';
            cout<<"{\n";
        }else{
            if(s[s.size()-1]=='}')t--;
            cout<<s<<'\n';
        }
    }
}
