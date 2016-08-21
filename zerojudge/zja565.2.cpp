#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, ni = 0, p, ans;
	char ch;
	for (cin >> n>>ws; ni < n; ni++){
		p = ans = 0;
		while (ch=getchar()){
			if (ch == '\n')break;
			if (ch == 'p')p++;
			else if (ch == 'q'&&p){p--; ans++; }

		}
		printf("%d\n", ans);
	}
}