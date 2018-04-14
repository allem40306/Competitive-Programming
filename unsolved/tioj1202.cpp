#include <bits/stdc++.h>
using namespace std;
struct loc{
	int l,h,r;
	bool operator <(const loc &b) const{
		return h<b.h;
	}
};
bool cmp(loc a,loc b){
	if(a.l!=b.l)
		return a.l<b.l;
}
int main() {
	cin.tie(NULL);
	loc arr[3005];
	int n,ai;
	while(cin>>n,n){
		for(ai=0;ai<n;ai++)
			cin>>arr[ai].h>>arr[ai].r;
		sort(arr,arr+n,cmp);
		priority_queue<loc>pq;
		int nh=10001;
		bool o=0;
	//	for(int i=0;i<ai;i++){
	//		cout<<arr[i].l<<arr[i].h<<arr[i].r<<'\n';
	//	}
		for(int i=0,j=0;i<=1000000000;i++){
			while(j<ai&&arr[j].l<=i){
				pq.push(arr[j]);
				j++;
			}
			while(pq.size()&&pq.top().r<=i){
				pq.pop();
			}
			if(pq.size()&&pq.top().h!=nh){
				if(o)cout<<' ';
				o=1;
				nh=pq.top().h;
				cout<<i<<' '<<nh;
			}
			if(o&&!pq.size()&&nh){
				nh=0;
				cout<<' '<<i<<' '<<nh;
			}
		}
		cout<<'\n';
	}
}
