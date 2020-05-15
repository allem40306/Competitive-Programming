#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,ans=1;
	cin>>a>>b;
	for(int i=0;i<a;i++){
	    if(ans<=b)ans*=2;
	    else ans+=b;
	}
	cout<<ans<<'\n';
}
