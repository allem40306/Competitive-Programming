#include <bits/stdc++.h>
using namespace std;
const int N=30;

int main(){
    int ma[N]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2},n;
    string s;
    while(cin>>s){
            n=-1;
        for(int i=0;i<s.size();i++){
            if(n!=ma[s[i]-'A']){
                if(ma[s[i]-'A'])cout<<ma[s[i]-'A'];
                n=ma[s[i]-'A'];
            }
        }
        cout<<'\n';
    }
}
