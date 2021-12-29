#include <bits/stdc++.h>
using namespace std;
const int MXN = 505;
const int MXM = 505;
using LL = long long;
using VI = vector<int>;

struct Data{
	int cnt;
	VI v;
	bool operator<(const Data&rhs)const{
		return cnt > rhs.cnt;
	}
};

int check(VI v)
{
	int res = 0, i = 17;
	while(1)
	{
		if(v[i] != 1)
		{
			return res;
		}
		++res;
		--i;
	}
}

void display(VI v)
{
	for(int i = 0; i != 6; ++i)
	{
		for(int j = 0; j != 6; ++j)
		{
			cout << v[i * 6 + j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{	
	set<VI> s;
	vector<int> v;
	priority_queue<Data>pq;
	v.resize(36);
	for(int i = 0, x; i < 36; ++i)
	{
		cin >> v[i];
		
	}
	int ans = -1;
	pq.push({0, v});
	while(!pq.empty())
	{
		Data d = pq.top();
		pq.pop();
		if(s.count(d.v))
		{
			continue;
		}
		s.insert(d.v);
		int res = check(d.v);
		if(res != 0)
		{
			ans = d.cnt + res;
			break;
		}
		for(int i = 0; i < 6; ++i)
		{
			for(int j = 0; j < 6; ++j)
			{
				int k = i * 6 + j;
				if(d.v[k] != 0 && (k % 6 == 0 || d.v[k] != d.v[k - 1]) && !((k - 6 >= 0 && d.v[k - 6] == d.v[k]) || (k + 6 < 36 && d.v[k + 6] == d.v[k])))
				{
					int k2 = k;
					while(k2 < i * 6 + 6 && d.v[k2 + 1] == d.v[k])++k2;
					if(k % 6 != 0 && d.v[k - 1] == 0)
					{
						swap(d.v[k - 1], d.v[k2]);
						pq.push({d.cnt + 1, d.v});
						swap(d.v[k - 1], d.v[k2]);
					}
					
					if(k2 % 6 != 5 && d.v[k2 + 1] == 0)
					{
						swap(d.v[k], d.v[k2 + 1]);
						pq.push({d.cnt + 1, d.v});
						swap(d.v[k], d.v[k2 + 1]);
					}
					
				}
			} 
		}
		for(int i = 0; i < 6; ++i)
		{
			for(int j = 0; j < 6; ++j)
			{
				int k = j * 6 + i;
				if(d.v[k] != 0 && (k / 6 == 0 || d.v[k] != d.v[k - 6]) && !((k - 1 >= 0 && d.v[k - 1] == d.v[k]) || (k + 1 < 36 && d.v[k + 1] == d.v[k])))
				{
					int k2 = k;
					while(k2 + 6 < 36 && d.v[k2 + 6] == d.v[k])k2+= 6;
					if(k / 6 != 0 && d.v[k - 6] == 0)
					{
						swap(d.v[k - 6], d.v[k2]);
						pq.push({d.cnt + 1, d.v});
						swap(d.v[k - 6], d.v[k2]);
					}
					
					if(k2 / 6 != 5 && d.v[k2 + 6] == 0)
					{
						swap(d.v[k], d.v[k2 + 6]);
						pq.push({d.cnt + 1, d.v});
						swap(d.v[k], d.v[k2 + 6]);
					}
					
				}
			} 
		}
	}
	if(ans > 10)
	{
		ans = -1;
	}
	cout << ans << '\n';
}
