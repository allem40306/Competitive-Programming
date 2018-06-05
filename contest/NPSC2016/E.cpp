#include <stdio.h>

long long ans(long long N, long long M) {
	if (!N)
		return 0;
	if (N == M)
		return 1;
	long long a, b, c;
	if (2*N <= M) {
		a = M/N+ans(M%N, N), b = M/N-1+ans(N, M%N+N);
		return a < b ? a : b;
	}
	a = 1+ans(M%N, N), b = (!(M%2) ? 2+ans(N-M/2, M) : 100000), c = (!(N%2) ? 2+ans(M-N/2, N) : 100000);
	return (a < b ? a : b) < c ? (a < b ? a : b) : c;
}

int main() {
	long long N, M, t;
	scanf("%lld%lld", &N, &M), N > M && (t = N, N = M, M = t), printf("%lld\n", ans(N, M));
}
