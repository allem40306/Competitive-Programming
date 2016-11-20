#include <iostream>
#include <string>
using namespace std;

int main(){
	unsigned long long int x,z;
	string y;
	while(cin>>x>>y>>z){
		int ans=1,len=y.size()-1;
		for(;len>=0;len--){
			if(y[len]=='1')ans=(ans*x)%z;
			x=(x*x)%z;
			}
		cout<<ans<<endl;
	}
}
