#include <bits/stdc++.h>
using namespace std;
int n,x;
int main(){
	cin>>n>>x;
	n%=6;
	while(n){
		if(n%2&&x<2)x=1-x;
		else if(n%2==0&&x>0)x=3-x;
		n--;
	}
	cout<<x<<endl;
}
