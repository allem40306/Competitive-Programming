#include <iostream>
#include <stack>
#include <new>
using namespace std;
long long t,ti,n,ni,ans,x;
struct Node{
	long long h,c;
}k;
stack <Node> s;
int main(){
	for(cin>>t;ti<t;ti++){
		k.c=1;
		cin>>n;
		ans=0;
		while(s.size())s.pop();
		for(ni=0;ni<n;ni++){
			cin>>x;
			while(s.size()&&s.top().h<x){
//				cout<<s.top().c<<endl;
				ans+=s.top().c;
				s.pop();
			}
			if(s.size()&&s.top().h>x)ans++;
			if(s.size()&&s.top().h==x){
//				cout<<s.top().c+(s.size()>1)<<endl;
				ans+=s.top().c+(s.size()>1);
				s.top().c++;
				continue;
			}
			k.h=x; k.c=1;
			s.push(k);
		}
		cout<<ans<<endl;
	}
}
