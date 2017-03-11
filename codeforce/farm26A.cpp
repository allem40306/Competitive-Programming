#include <bits/stdc++.h>
using namespace std;
#define N 10000
int x,d;
int main(){
	cin>>x>>d;
	if(d>=0)cout<<2*x+d-1<<endl;
	else cout<<2*(x-1)<<endl;	
}
