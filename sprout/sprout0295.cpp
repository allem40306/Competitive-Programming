#include <iostream>
using namespace std;
long long n,i,a,b,c;
int main(){
	cin.tie(NULL);
	for(cin>>n;i<n;i++){
		cin>>a>>b>>c;
		if(a+b>c)cout<<"Yes.\n";
		else cout<<"No.\n";
	}
}
