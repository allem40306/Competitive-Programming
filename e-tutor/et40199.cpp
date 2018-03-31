#include <iostream>
using namespace std;

void print(long long int n){
    cout<<n<<" =";
    for(int i=31;i>=0;i--){
        if(i%8==7)cout<<' ';
        cout<<((n>>i)&1);
    }
    cout<<" \n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    string s="The packed character representation is:\n";
    long long n;
    cin>>n;
    cout<<s;
    print(n);
    cout<<'\n';
    print(n&4278190080);
    print(n&16711680);
    print(n&65280);
    print(n&255);
}
