#include <bits/stdc++.h>
using namespace std;
const int MXN = 55;
using LL = long long;

int main()
{	
	int t, n;
	priority_queue <LL, vector<LL>, greater<LL>> pq;
	cin >> t;
	while(t--)
	{
		LL x, y, ans = 0;
		cin >> n;
		while(!pq.empty())pq.pop();
		for(int i = 0; i < n; ++i)
		{
			cin >> x;
			pq.push(x);
		}
		while(pq.size() > 1)
		{
			x = pq.top(); pq.pop();
			y = pq.top(); pq.pop();
			x += y;
			ans += x;
			pq.push(x);
		}
		cout << ans << '\n';
	}
}
