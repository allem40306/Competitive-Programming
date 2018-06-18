#include <iostream>
using namespace std;

int main() {
    long long n,p,m;
    while(cin>>n){
        p=m=1;
        while(1){
            if(p%2)m*=9;
            else m*=2;
            if(m>=n)break;
            p++;
        }
        printf(p%2?"Stan wins.\n":"Ollie wins.\n");
    }
}
