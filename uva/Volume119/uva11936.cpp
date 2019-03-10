#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a[3];
    cin>>n;
    while(n--){
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]>a[2])cout<<"OK\n";
        else cout<<"Wrong!!\n";
    }
}
