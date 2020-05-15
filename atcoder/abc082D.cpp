#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int x,y;
    cin>>s>>x>>y;
    vector<int>a,b;
    bool isx=1;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='F'){
            c++;
        }else{
            if(isx){
                a.push_back(c);
            }else{
                b.push_back(c);
            }
            c=0;
            isx=(!isx);
        }
    }
    if(s[s.size()-1]=='F'){
        if(isx){
            a.push_back(c);
        }else{
            b.push_back(c);
        }
    }
    const int N=8005;
    bool dpa[N]={1},dpb[N]={1};
    int suma=0,sumb=0;
    for(int i=1;i<a.size();i++){
        suma+=a[i];
        for(int j=suma;j-a[i]>=0;j--){
            if(dpa[j-a[i]])dpa[j]=1;
        }
    }
    for(int i=0;i<b.size();i++){
        sumb+=b[i];
        for(int j=sumb;j-b[i]>=0;j--){
            if(dpb[j-b[i]])dpb[j]=1;
        }
    }
    x=abs(x-a[0]);
    y=abs(y);
    if((suma>=x&&sumb>=y)&&(((suma-x)%2==0&&dpa[(suma-x)/2]))&&(((sumb-y)%2==0&&dpb[(sumb-y)/2]))){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
