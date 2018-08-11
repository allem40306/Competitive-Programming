#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t >> ws >> ws;
	while (t--) {
		map<string, double>tb;
		double n = 0.0;
		while (getline(cin, s)&& s != "") {
			n += 1.0;
			if (tb.find(s) != tb.end()) {
				tb[s] += 1.0;
			} else {
				tb[s] = 1.0;
			}
		}
		for(map<string, double>::iterator it=tb.begin();it!=tb.end();it++){
			cout<<fixed<<setprecision(4)<<it->first<<' '<<it->second/n*100<<'\n';
		}
		if(t)cout<<'\n';
	}
}