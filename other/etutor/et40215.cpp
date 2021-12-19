#include <iostream>
#include <cstdarg>
using namespace std;
int sum(int n,...){
    va_list vl;
    va_start(vl,n);
    int tot=0+va_arg(vl,int);
    for(int i=1;i<n;i++){
        tot+=va_arg(vl,int);
    }
    va_end(vl);
    return tot;
}

int main(){
    int n;
    int a[5];
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<sum(n,a)<<'\n';
    }
}
