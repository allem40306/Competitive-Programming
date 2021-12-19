#include <iostream>
using namespace std;
#define largest3(a,b,c) ((a<=b&&a<=c)?a:(b<=c?b:c))
#define largest2(a,b,c) ((a<=b&&a>=c)||(a>=b&&a<=c)?a:(b<=a&&b>=c)||(b>=a&&b<=c)?b:c)

int main(){
    int a,b,c;
    while(cin>>a>>b>>c){
        cout<<a+b+c-largest3(a,b,c)-largest2(a,b,c)<<'\n';
    }
}
