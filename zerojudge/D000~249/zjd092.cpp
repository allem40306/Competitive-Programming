#include<iostream>
#include<algorithm>
using namespace std;

struct abc{
	int a,b,c,d;
}s[1010];

bool comp(abc a, abc b){
	if(a.c!=b.c)
		return a.c > b.c;
	return a.d > b.d;
}

int main(){
	int  n;
	while (	cin >> n,n){
		for (int i = 0; i != n; i++){
			cin >> s[i].a >> s[i].b;
			s[i].c = s[i].a + s[i].b;
			if (s[i].a > s[i].b) s[i].d = 1;
			else if (s[i].a == s[i].b) s[i].d = 0;
			else s[i].d = -1;
		}
		sort(s, s + n, comp);
		for (int i = 0; i != n; i++){
			if (s[i].a > s[i].b)cout << '>' << s[i].c << ' ';
			else if (s[i].a < s[i].b)cout << '<' << s[i].c << ' ';
			else if (s[i].a == s[i].b)cout << '=' << s[i].c << ' ';
		}
		cout << endl;
	}
}