#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    map<int,int>tba,tbb;
    int x,y;
    while(cin>>x){
        switch(x){
            case 1:
                cin>>y;
                mn.push(y);
                mx.push(y);
                break;
            case 2:
                while(tbb.find(mx.top())!=tbb.end()&&tbb[mx.top()]){
                    tbb[mx.top()]--;
                    mx.pop();
                }
                cout<<mx.top()<<'\n';
                if(tba.find(mx.top())!=tba.end()){
                    tba[mx.top()]++;
                }else{
                    tba[mx.top()]=1;
                }
                mx.pop();
                break;
            case 3:
                while(tba.find(mn.top())!=tba.end()&&tba[mn.top()]){
                    tba[mn.top()]--;
                    mn.pop();
                }
                cout<<mn.top()<<'\n';
                if(tbb.find(mn.top())!=tbb.end()){
                    tbb[mn.top()]++;
                }else{
                    tbb[mn.top()]=1;
                }
                mn.pop();
                break;
        }
    }
}
