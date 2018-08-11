#include <bits/stdc++.h>
using namespace std;
string s;
typedef long long LL;
const int N=305;
const LL mod=1000000000;
LL a[N][N];

LL dp(int L, int R) {
	if (L == R)return 1;
	if(s[L]!=s[R])return 0;
	LL& ans = a[L][R];
	if (ans >= 0)return ans;
	ans = 0;
	for (int i = L + 2; i <= R; i++) {
		if(s[L]==s[i])ans=(ans+(LL)dp(L+1,i-1)*dp(i,R))%mod;
	}
	return ans;
}

int main() {
	while (cin >> s) {
		memset(a, -1, sizeof(a));
		cout << dp(0, s.size() - 1)<<'\n';
	}
}