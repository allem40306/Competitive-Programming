#include <bits/stdc++.h>
using namespace std;
long long n,i,x;
struct mon{
	long long t,s;
	mon(long long t,long long s):t(t),s(s){}
	bool operator<(const mon& b)const{
		if(s!=b.s)
			return s>b.s;
	}
};
priority_queue<mon>pq;
int main(){
	cin.tie(NULL);
	for(cin>>n;i<n;i++){
		cin>>x;
		pq.push(mon(1,x));
	}
	mon a=mon(0,0),b=mon(0,0);
	while(pq.size()>1){
		a=pq.top(); pq.pop();
		b=pq.top(); pq.pop();
//		cout<<a.s<<' '<<b.s<<endl;
		if(a.s*2<b.s){
			n-=a.t;
			pq.push(mon(b.t,a.s+b.s));
		}else
			pq.push(mon(a.t+b.t,a.s+b.s));
	}
	cout<<n<<endl;
}
