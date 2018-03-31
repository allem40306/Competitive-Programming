#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r;
    while(cin>>s>>r){
        cout<<(int(r[0]-s[0])+26)%26<<'\n';
    }
}
