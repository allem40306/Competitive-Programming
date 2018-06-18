#include <iostream>
#include <string>
using namespace std;

int main(){
    string s,r;
    bool b=1;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(b&&s[i]=='-'){
            if(s[i+1]=='-'){
                i++;
            }else{
                b=0;
                r+='-';
            }
        }else{
            r+=s[i];
        }
    }
    if(r=="-0")cout<<"0\n";
    else cout<<r<<'\n';
}
