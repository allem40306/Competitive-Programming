#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    for(int i=n/5;i>=0;i--){
        if((n-5*i)%3)continue;
        cout<<i+(n-5*i)/3<<'\n';
    return 0;
    }
    cout<<"This is Kongming's Trap!!!\n";
}