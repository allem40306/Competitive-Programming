#include <iostream>
#include <cmath>//max 
#include <algorithm>//sort
using namespace std;

struct owo{
	int x,y;
};

bool cmp2(owo a,owo b){
	if(a.x!=b.x)
	    return a.x<b.x;
	return a.y<b.y;
}

int main(){
	int n,ans,s,t;
	owo a[10005];
	while(cin>>n){
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y;
		}
		sort(a,a+n,cmp2);
		s=a[0].x; t=a[0].y;
		for(int i=1;i<n;i++){
			if(a[i].x<t){
				t=max(t,a[i].y);
			}else{
				ans+=t-s;
				s=a[i].x;
				t=a[i].y;
			}
		}
		cout<<ans+t-s<<'\n';
	}	
}
