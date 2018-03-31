#include <bits/stdc++.h>
using namespace std;

string s,t;
bool ok(int a,int b,int c){
    s=t="";
    while(a>=0){
        s+=char(a%10+'0');
        a=a?a/10:-1;
    }
    while(b>=0){
        s+=char(b%10+'0');
        b=b?b/10:-1;
    }
    while(c>=0){
        t+=char(c%10+'0');
        c=c?c/10:-1;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

int main(){
    vector<int>v[3];
    for(int i=10,r=0;i<=1000;i*=10,r++){
        for(int j=i;j<10*i;j++){
            for(int k=10*i*i/j;k<10*i;k++){
                if(j*k>=100*i*i)break;
                if(ok(j,k,j*k))v[r].push_back(j*k);
            }
        }
    }
//    cout<<"ok";
//    int n;
//    while(cin>>n){
//        n=n/2-2;
//        for(int i=0;i<v[n].size();i++){
//            cout<<v[n][i]<<'\n';
//        }
//    }
}
