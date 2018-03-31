#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define pi 3.14159

int main(){
    int n;
    while(cin>>n){
        if(!n){
            cout<<"no area\n";
            continue;
        }
        cout<<fixed<<setprecision(3)<<double(n)*double(n)*pi<<'\n';
    }
}
