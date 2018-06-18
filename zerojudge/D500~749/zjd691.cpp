#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int x;
    vector<int>v,w,u;
    vector<int>::iterator it;
    while(getline(cin,s)){
        v.clear();
        w.clear();
        u.clear();
        stringstream ss(s);
        while(ss>>x){
            v.push_back(x);
        }
        getline(cin,s);
        stringstream rr(s);
        while(rr>>x){
            w.push_back(x);
        }
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        w.erase(unique(w.begin(),w.end()),w.end());
        if(v==w){
            cout<<"A equals B\n";
            continue;
        }
        set_intersection(v.begin(),v.end(),w.begin(),w.end(),back_inserter(u));
        if(u.size()==0&&v.size()&&w.size()){
            cout<<"A and B are disjoint\n";
        }else if(v==u){
            cout<<"A is a proper subset of B\n";
        }else if(w==u){
            cout<<"B is a proper subset of A\n";
        }else{
            cout<<"I'm confused!\n";
        }
    }
}
