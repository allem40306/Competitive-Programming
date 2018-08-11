#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        if(s.size()==1&&(s[0]=='0'||s[0]=='1')){
            cout<<(s[0]=='0'?"1\n":"66\n");
        }else{
            int m=s[s.size()-1]-'0';
            m=m%5;
            switch (m){
            case 1:
                cout<<"16\n";
                break;
            case 2:
                cout<<"56\n";
                break;
            case 3:
                cout<<"96\n";
                break;
            case 4:
                cout<<"36\n";
                break;
            default:
                cout<<"76\n";
                break;
            }
        }
    }
}
