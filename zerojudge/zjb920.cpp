#include <cstdio>

int main(){
	long long a,b,c,d;
	scanf("%lld %lld %lld",&a,&b,&c);
	if(b-a==c-b)printf("%lld %lld %lld\n",c+(b-a),c+(b-a)*2,c+(b-a)*3);
	else if(a>b)printf("%lld %lld %lld\n",c/(a/b),c/(a/b)/(a/b),c/(a/b)/(a/b)/(a/b));
	else printf("%lld %lld %lld\n",c*(b/a),c*(b/a)*(b/a),c*(b/a)*(b/a)*(b/a));
}
