#include <bits/stdc++.h>
using namespace std;

int main(){
    double t1,m1,t2,m2;
    string s;
    vector<string>v,w;
    bool ok;
    while(cin>>t1>>s){
        v.clear();
        w.clear();
        if(s=="s")t1*=100;
        cin>>m1>>s;
        if(s=="MB")m1*=1000;
        cin>>t2>>s;
        if(s=="s")t2*=100;
        cin>>m2>>s;
        if(s=="MB")m2*=1000;
        getline(cin,s);
        while(getline(cin,s),s!="(This is the end of the user's output.)"){
            v.push_back(s);
        }
        while(getline(cin,s),s!="(This is the end of the correct answer.)"){
            w.push_back(s);
        }
        if(t1>t2){
            cout<<"TLE\n";
        }else if(m1>m2){
            cout<<"MLE\n";
        }else if(v.size()>w.size()){
            cout<<"OLE\n";
        }else{
            ok=0;
            if(v.size()==w.size()){
                ok=1;
                for(int i=0;i<v.size();i++){
                    if(v[i]!=w[i]){
                        ok=0;
                    }
                }
            }
            if(ok){
                cout<<"AC\n";
            }else{
                cout<<"WA\n";
            }
        }
    }
}
