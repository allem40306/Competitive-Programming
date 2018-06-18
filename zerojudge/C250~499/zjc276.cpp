#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r;
    int n,a,b;
    cin>>s>>n;
    while(n--){
        cin>>r;
        a=b=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(s[i]==r[j]){
                    if(i==j)a++;
                    else b++;
                }
            }
        }
        cout<<a<<'A'<<b<<"B\n";
    }
}
