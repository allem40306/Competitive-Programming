#include <stdio.h>
#include <math.h>

long long int test(long long a,long long b)
{
	long long i=(b+sqrt(b*b-4*a)+1e-9)/2,j=(b-sqrt(b*b-4*a)+1e-9)/2;
	if(a+b == b && a*b==a) return a+b;
	else if(a+b == a && a*b==b) return a+b;
	return 0;
}

int main() {
	long long N, M, t,tmp,c;
	for (scanf("%lld%lld", &N, &M), N < M && (t = N, N = M, M = t), c = 0; N; )
	{
		tmp = test(M,N);
        if(tmp) break;
        c++, t = M-N, M = N, N = t;		
	}
	if(tmp) c+=tmp;
	printf("%lld\n", c);
}
