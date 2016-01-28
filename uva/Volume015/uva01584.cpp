#include <cstdio>
#include <cstring>
#define maxn 105
#define scanf scanf_s

int less(const char* s, int p, int q){
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[(p + i) % n] != s[(q + i) % n])
			return s[(p + i) % n] < s[(q + i) % n];
	return 0; //¬Ûµ¥
}

int main(){
	int t;
	char s[maxn];
	scanf("%d", &t);
	while (t--){
		scanf("%s", s, 105);
		int ans = 0;
		int n = strlen(s);
		for (int i = 1; i < n; i++)
			if (less(s, i, ans))ans = i;
		for (int i = 0; i < n; i++)
			putchar(s[(i + ans) % n]);
		putchar('\n');
	}
}