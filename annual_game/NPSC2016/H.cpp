#include <algorithm>
#include <stdio.h>

struct SV{long long s, v;} sv[25];

int main() {
	static long long n, m, i, j, r, c, v, d[5000000] = {}, dd[5000000] = {}, t; char s[25];
	for (scanf("%lld%lld", &n, &m), i = j = 0; i != m; i++) {
		for (scanf("%s%lld", s, &v), c = r = 0; r != n; r++)
			c *= 2, s[r] == '1' && c++;
		for (sv[j].s = c, sv[j].v = v, j++, r = 0; r != j; r++)
			!dd[sv[j-1].s|sv[r].s] && sv[j-1].s != sv[r].s && (d[sv[j-1].s|sv[r].s] += sv[r].v), d[sv[j-1].s|sv[r].s] += sv[j-1].v, dd[sv[j-1].s|sv[r].s]++;
	}
	for (std::sort(d+1, d+(1<<n)), i = 1, t = 0; i != 1<<n; i++)
		t += i*d[i], printf("%lld %lld | ", i, d[i]);
	printf("%lld\n", t);
}
