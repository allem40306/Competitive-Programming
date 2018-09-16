#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n, pos = 0, x;
		int ins[N];
		string s;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			if (s[0] == 'L') {
				ins[i] = -1;
			} else if (s[0] == 'R') {
				ins[i] = 1;
			} else {
				cin >> s >> x;
				ins[i] = ins[x];
			}
			pos+=ins[i];
		}
		cout<<pos<<'\n';
	}

}