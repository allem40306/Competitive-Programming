#include <stdio.h>

int main() {
	long long n, i, w; char s[1000];
	for (; ~scanf("%s", s); printf(w && i < 6 ? "%06X\n" : "Error\n", n))
		for (w = 1, n = i = 0; s[i]; i++)
			'A' <= s[i] && s[i] <= 'Z' && (s[i] += 'a'-'A'), s[i] == 'z' && (w = 0), n *= 25, n += s[i]-'a'+1;
}
