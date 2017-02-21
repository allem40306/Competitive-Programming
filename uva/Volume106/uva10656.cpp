#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ni,x;
	bool b;
	while(cin>>n,n){
		b=0;
		for(ni=0;ni<n;ni++){
			cin>>x;
			if(x){
				if(b)cout<<' ';
				b=1;
				cout<<x;
			}
		}
		if(!b)cout<<"0";
		cout<<endl;
	}
}
