#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int>v;
	int n;
	while (cin >> n) {
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int val=(v[(n-1)/2]),cnt=0;
		for(auto x:v){
			cnt+=(x==val||x==v[n/2]);
		}
		cout<<val<<' '<<cnt<<' '<<v[n/2]-val+1<<'\n';
	}
}