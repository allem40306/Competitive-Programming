#include <bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];
int main(){
    string s;
    int ans,v,ar;
    while(cin>>s){
        ans=1;
        while(ans<=10000){
            ar=0;
            for(int i=1;i<=s.size();i++){
                v=ans+(s[i]-'A');
                if(v>100){
                    a[ar++]=v/100;
                    a[ar++]=(v%100)/10;
                    a[ar++]=v%10;
                }else if(v>10){
                    a[ar++]=(v%100)/10;
                    a[ar++]=v%10;
                }else{
                    a[ar++]=v%10;
                }
            }
        }

    }
}
