#include <bits/stdc++.h>
using namespace std;
const int MXN = 55;
using LL = long long;

int main()
{	
	int t;
	LL n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << ((n * (n + 1)) ^ (n + 1)) << '\n';
	}
}
