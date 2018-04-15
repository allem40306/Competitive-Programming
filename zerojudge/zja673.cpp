#include <iostream>
#include <algorithm>
using namespace std;
#define N 2000

struct task{
	int i,d,f;
};

bool cmp(task a,task b){
	if(a.d*b.f!=b.d*a.f)
	return a.d*b.f<b.d*a.f;
	return a.i<b.i;
}

int main(){
	int tt,n,ti=0;
	task t[N];
	for(cin>>tt;ti<tt;ti++){
		cin>>n;
		for(int i=0;i<n;i++){
			t[i].i=i;
			cin>>t[i].d>>t[i].f;
		}
		sort(t,t+n,cmp);
		for(int i=0;i<n;i++){
			if(i)cout<<' ';
			cout<<t[i].i+1;
		}
		if(ti<tt-1)cout<<"\n";
		cout<<"\n";
	}
}