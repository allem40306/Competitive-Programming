#include <iostream>
using namespace std;

int main(){
    int a[2]={},n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        a[i&1]+=x;
    }
    cout<<(a[0]>a[1]?"left\n":"right\n");
}
