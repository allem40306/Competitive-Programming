#include <stdio.h>
#include <math.h>

long long int two(long long int n)
{
	for(long long int i = sqrt(n); i>0;i--) if(n%i == 0) return i;
}

int main()
{
	long long int q,sq,a,b,c,tmp,i,min=9223372036854775807,ra,rb,rc;
	scanf("%lld",&q),sq=sqrt(q);
	for(i=1;i<=sq;i++)
	{
		if(q%i == 0) 
		{
			c=q/i,b = two(c),a = c/b,c=i;
			if(c>a && c>b) tmp = c,c=b,b=a,a=tmp;
			else if (c>b) tmp = c,c=b,b=tmp;
			if(2*(a*b+b*c+a*c) < min || a+b+c < ra+rb+rc && 2*(a*b+b*c+a*c) < min) min=2*(a*b+b*c+a*c),ra=c,rb=b,rc=a;
  		}
	}
	printf("%lld %lld %lld %lld\n",2*(ra*rb+rb*rc+ra*rc),ra,rb,rc);
}
