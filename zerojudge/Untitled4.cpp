#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define N 1000000

int main(){
	static long long int t, ti = 0, n, ni, a[N], ar, ans, w, x;
	stack<int>st;
	for (scanf("%lld", &t); ti<t; ti++){
		scanf("%lld", &n);
		for (ni = 0; ni<n; ni++)scanf("%lld", &a[ni]);
		sort(a, a + n);
		w = ar = ans = 0;
		while (st.size())st.pop();
		scanf("%lld", &n);
		for (ni = 0; ni<n; ni++){
			scanf("%lld", &x);
			if (x == 1){
				ans += 2 * w + a[ar];
				st.push(a[ar]);
				w += a[ar++];
			}
			else{
				x = st.top(); st.pop();
				ans += 2 * w - x;
				w -= x;
			}
		}
		printf("%lld\n", ans);
	}
}
