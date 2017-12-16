#include <bits/stdc++.h>
using namespace std;
const int N=105;
string s;
int a[N],ar,x,v;

void tra(int L,int R){
    while(L<R){
        swap(a[L],a[R]);
        L++; R--;
    }
}

int main(){
//    freopen("120.out","w",stdout);
    while(getline(cin,s)){
        cout<<s<<'\n';
        stringstream ss(s);
        ar=1;
        while(ss>>a[ar])ar++;
//        cout<<ar<<'\n';
        for(int i=ar-1;i>=1;i--){
            v=*max_element(a+1,a+i+1);
            x=find(a+1,a+i+1,v)-a;
//            cout<<i<<' '<<x<<'\n';
            if(x==i)continue;
            if(x!=1){
                cout<<ar-x<<' ';
                tra(1,x);
//                cout<<'\n';
//                for(int i=1;i<ar;i++)cout<<a[i]<<' ';
//                cout<<'\n';
            }
            cout<<ar-i<<' ';
            tra(1,i);
//            cout<<'\n';
//            for(int i=1;i<ar;i++)cout<<a[i]<<' ';
//            cout<<'\n';
        }
        cout<<"0\n";
    }
}
