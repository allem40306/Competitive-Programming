#include <bits/stdc++.h>
using namespace std;

int main()
{	string s;
	bool ok = 0;
	while(cin >> s)
	{
		if(s == "bubble" || s== "tapioka")
		{
			continue;
		}
		if(ok)cout << ' ';
		ok = true;
		cout << s;
	}
	if(ok == false)
	{
		cout << "nothing";
	}
	cout << '\n';
}
