#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int m,c,a[100];
    string s;
    cin>>m;
    for(int i=0;i<m;i++){
            cin>>c;
            int x=0,o=0,n=0;
            cin>>s;
            for(int i=0;i<s.size();i++){
                     if(n&&(s[i]>'9'||s[i]<'0')){
                         x++; a[x]=n; n=0;
                    }
                     else if(s[i]<='9'&&s[i]>='0')n=n*10+(s[i]-'0');
            }
            for(int i=1;i<=x;i++){
                    if(i*2<=x&&abs(a[i*2]-a[i])<=c){
                        if(o)cout<<' ';
                        o=1;
                        cout<<char('A'+i-1)<<char('A'+i*2-1);
                    }
                     if(i*2+1<=x&&abs(a[i*2+1]-a[i])<=c){
                        if(o)cout<<' ';
                        o=1;
                        cout<<char('A'+i-1)<<char('A'+i*2+1-1);
                    }
            }
            cout<<'\n';
    }
} 
