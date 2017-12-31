#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<2*n+3;i++)cout<<'#';
    cout<<'\n';
    for(int j=0;j<n;j++){
        cout<<'#';
        for(int i=0;i<n;i++)cout<<'.';
        cout<<'#';
        for(int i=0;i<n;i++)cout<<'.';
        cout<<'#';
        cout<<'\n';
    }
    for(int i=0;i<2*n+3;i++)cout<<'#';
    cout<<'\n';
    for(int j=0;j<n;j++){
        cout<<'#';
        for(int i=0;i<n;i++)cout<<'.';
        cout<<'#';
        for(int i=0;i<n;i++)cout<<'.';
        cout<<'#';
        cout<<'\n';
    }
    for(int i=0;i<2*n+3;i++)cout<<'#';
    cout<<'\n';
}
