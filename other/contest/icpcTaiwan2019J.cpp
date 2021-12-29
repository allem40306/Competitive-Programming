#include <bits/stdc++.h>
using namespace std;
const int MXN = 505;
const int MXM = 505;
using LL = long long;
int n, m;
bitset<MXN> b[MXM];

bool OK(int n, int m, int s) // select
{
	bitset<MXN> tmp;
	tmp.reset();
	for(int i = 0; i < m; ++i)
	{
		if((s >> i) & 1)
		{
			tmp |= b[i];
		}
	}
	for(int i = 0; i < n; ++i)
	{
		if(tmp[i] == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{	
	int t;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < m; ++i)
		{
			b[i].reset();
			cin >> s;
			for(int j = 0; j != (int)s.size(); ++j)
			{
				if(s[j] == '1')
				{
					b[i][j] = 1;
				}
			}
		}
		int ans = 20;
		for(int i = 1; i < (1 << m) - 1; i++)
		{
			if(OK(n, m, i))
			{
				ans = min(ans, __builtin_popcount((unsigned) i));
			}
		}
		if(ans == 20)
		{
			ans = -1;
		}
		cout << ans << '\n';
	}
}
