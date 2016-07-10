#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define N 52

struct tot{
	int a, t;
}t[N];

bool cmp(tot a, tot b){
	if (a.t != b.t)return a.t > b.t;
	return a.a < b.a;
}

int main(){
	string s;
	while (getline(cin, s)){
		for (int i = 0; i < N; i++)t[i].a = i, t[i].t = 0;
		int lens = s.size();
		for (int i = 0; i < lens; i++){
			if ('A' <= s[i] && s[i] <= 'Z')t[s[i] - 'A'].t++;
			else if ('a' <= s[i] && s[i] <= 'z')t[s[i] - 'a' + 26].t++;
		}
		sort(t, t + N, cmp);
		int mt = t[0].t, tr = 0;
		while (t[tr].t == mt&&tr<52){
			if (t[tr].a>25)printf("%c", 71 + t[tr].a);
			else printf("%c", 65 + t[tr].a);
			tr++;
		}
		printf(" %d\n", mt);
	}
}