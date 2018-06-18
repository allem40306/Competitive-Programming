#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,a[10],ar=0;
    int style[10][5]={1,3,0,3,1,0,1,0,1,0,1,1,1,2,1,1,1,1,1,1,0,3,1,1,0,1,2,1,1,1,1,2,1,3,1,1,1,0,1,0,1,3,1,3,1,1,3,1,1,1};
    string s;
    while(cin>>m>>s,(s!="0")||m){
        ar=0;
        for(int i=s.size()-1;i>=0;i--){
            a[ar]=(s[i]-'0');
            ar++;
        }
        for(int i=0;i<5;i++){
            if(i&1){
                s="";
                for(int j=ar-1;j>=0;j--){
                    s+=((style[a[j]][i]&2)?'|':' ');
                    for(int k=0;k<m;k++)s+=' ';
                    s+=((style[a[j]][i]&1)?'|':' ');
                    if(j)s+=' ';
                }
                for(int j=0;j<m;j++)cout<<s<<'\n';
            }else{
                for(int j=ar-1;j>=0;j--){
                    cout<<' ';
                    for(int k=0;k<m;k++){
                        cout<<((style[a[j]][i])?'-':' ');
                    }
                    cout<<' ';
                    if(j)cout<<' ';
                }
                cout<<'\n';
            }
        }
        cout<<'\n';
    }
}
