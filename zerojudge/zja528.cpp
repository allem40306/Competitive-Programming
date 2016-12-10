#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 2000

struct str{
	int p, len;
	string s;
};

bool cmp(str a, str b){
	if (a.p != b.p)
		return a.p < b.p;
	if (a.p == 0){
		if (a.len != b.len)
			return a.len > b.len;
		for (int i = 1; i < a.len; i++)
			if (a.s[i] != b.s[i])
				return a.s[i]>b.s[i];
	}
	else{
		if (a.len != b.len)
			return a.len < b.len;
		for (int i = 0; i < a.len; i++)
			if (a.s[i] != b.s[i])
				return a.s[i]<b.s[i];
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n){
		str a[N];
		for (int i = 0; i < n; i++){
			cin >> a[i].s;
			a[i].p = ((a[i].s[0] == '-') ? 0 : 1);
			a[i].len = a[i].s.size();
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++)
			cout << a[i].s << endl;
	}
}
