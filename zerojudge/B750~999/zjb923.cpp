#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    stack<int>s;
    cin>>n;
    while(n--){
        cin>>x;
        if(x==1){
            s.pop();
        }else if(x==2){
            cout<<s.top()<<'\n';
        }else{
            cin>>y;
            s.push(y);
        }
    }
}
