#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define N 26

struct tot{
	int a, t;
}t[N];

bool cmp(tot a, tot b){
	if (a.t != b.t)return a.t > b.t;
	return a.a < b.a;
}

int main(){
	int n;
	while (cin >> n >> ws){
		for (int i = 0; i < N; i++)t[i].a = i, t[i].t = 0;
		while (n--){
			string s;
			getline(cin, s);
			int lens = s.size();
			for (int i = 0; i < lens; i++)
				if (isalpha(s[i]))t[toupper(s[i]) - 'A'].t++;
		}
		sort(t, t + N, cmp);
		int tr = 0;
		while (t[tr].t){
			printf("%c %d\n", 65 + t[tr].a, t[tr].t);
			tr++;
		}
	}
}