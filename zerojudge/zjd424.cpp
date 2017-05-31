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
	loc arr[5005];
	int ai=0;
	while(cin>>arr[ai].l){
		cin>>arr[ai].h>>arr[ai].r;
		ai++;
	}
	sort(arr,arr+ai,cmp);
	priority_queue<loc>pq;
	int nh=10001;
	bool o=0;
//	for(int i=0;i<ai;i++){
//		cout<<arr[i].l<<arr[i].h<<arr[i].r<<'\n';
//	}
	for(int i=0,j=0;i<=10000;i++){
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
