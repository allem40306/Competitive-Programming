#include <iostream>
#include <iomanip>
using namespace std;
#define avg(sum,n) sum/(double)n

int main(){
    int n;
    double sum,x;
    while(cin>>n){
        sum=0;
        for(int i=0;i<n;i++){
            cin>>x;
            sum+=x;
        }
        cout<<fixed<<setprecision(2)<<avg(sum,n)<<'\n';
    }
}
