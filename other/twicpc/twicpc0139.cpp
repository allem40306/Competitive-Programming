#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	long long x,y;
	cin>>x; 
	for(y=-1000000;y<=1000000;y++){
		if(y*(5*y-4)*(y+1)==x){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
} 
