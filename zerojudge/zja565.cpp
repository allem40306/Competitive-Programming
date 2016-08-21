#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, ni = 0, p, ans;
	static char s[10000000];
	for (cin >> n; ni < n; ni++){
		p = ans = 0;
		scanf_s("%s", s);
		for (int i = 0; s[i]; i++){
			if (s[i] == 'p')p++;
			else if (s[i]== 'q'&&p){ p--; ans++; }
		}
		printf("%d\n", ans);
	}
}