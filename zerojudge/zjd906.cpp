#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct abc{
	int n, t;
	string ch;
}s[7];

bool com1(abc a, abc b){
		return a.n < b.n;
}

bool com2(abc a, abc b){
	if (a.t!=b.t)
	return a.t < b.t;
	return a.n < b.n;
}

int main(){
	int m, n, a;
	while (cin >> m >> n){
		for (int i = 0; i < 6; i++)
			cin >> s[i].ch >> s[i].n >> s[i].t;
		if (m % 2)
			sort(s, s + 6, com1);
		else
			sort(s, s + 6, com2);
		a = 2 - n + 6 * (n > 2);
		cout << s[a].ch << endl;
	}
}