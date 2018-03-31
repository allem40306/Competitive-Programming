#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r,t;
    while(getline(cin,s),s!="DONE"){
        r="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                r+=tolower(s[i]);
            }
        }
        t=r;
        reverse(r.begin(),r.end());
        if(r==t){
            cout<<"You won't be eaten!\n";
        }else{
            cout<<"Uh oh..\n";
        }
    }
}
