#include <iostream>
using namespace std;

int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    a*=d; c*=b;
    if(a==c){
        cout<<"=\n";
    }else if((a>c&&b*d>0)||(a<c&&b*d<0)){
        cout<<">\n";
    }else{
        cout<<"<\n";
    }
}
