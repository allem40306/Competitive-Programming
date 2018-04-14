#include <iostream>
#include <string>
using namespace std;

int main() { 
    long long m,n,a,t=0;
        while(cin>>m>>n>>a){
                cout<<(m/a+(m%a>0))*(n/a+(n%a>0))<<endl;
                if(t++)cout<<endl;
}
}
