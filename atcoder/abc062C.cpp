#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	unsigned long long h,w;
	cin>>h>>w;
	if(h%3==0||w%3==0)cout<<"0\n";
	else{
		unsigned long long ans=100000000000000,a1,a2,a3;
		for(unsigned long long i=1;i<h;i++){
			a1=i*w; a2=(h-i)*((w+1)/2); a3=(h-i)*(w/2);
			ans=min(ans,max(a1,a2)-min(a1,a3));
		}
		for(unsigned long long i=1;i<w;i++){
			a1=i*h; a2=(w-i)*((h+1)/2); a3=(w-i)*(h/2);
			ans=min(ans,max(a1,a2)-min(a1,a3));
		}
		cout<<ans<<'\n';
	}
}
