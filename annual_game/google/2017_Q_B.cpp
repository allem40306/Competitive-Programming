#include <bits/stdc++.h>
using namespace std;
long long t,i=0,n,a[100],ai,ni;
bool z;
int main(){
	cin.tie(NULL);
	for(cin>>t;i<t;i++){
		cin>>n;
		ni=ai=-1;
		while(n){
			a[++ai]=n%10;
			n/=10;
		}
		for(int i=1;i<=ai;i++){
			if(a[i]>a[i-1]){
				a[i]--;
				ni=i-1;
			}
		}
		z=1;
		cout<<"Case #"<<i+1<<": ";
		for(int i=ai;i>=0;i--){
			if(z&&!a[i]){
				z=0;
				continue;
			}
			z=0;
			if(i>ni)cout<<a[i];
			else cout<<'9';
		}
		cout<<'\n';
	}
}
