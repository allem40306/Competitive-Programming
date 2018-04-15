#include <iostream>
using namespace std;
#define MAX 0x7FFFFFFFFFFFFFFF
#define LL long long
#define abs(a) ((a)<0ll?-(a):(a))

LL lcm(LL x, LL y){
	LL z, xx = x, yy = y;
	if (x < y)z = x, x = y, y = z;
	if (y == 0ll)return 0ll;
	while (x % y){z = x%y, x = y, y = z;}
	xx /= y;
	if (xx > MAX / yy) return MAX;
	else return xx*yy;
}

long long amb(LL a, LL x, LL y, LL l){
	LL ans = ((x == 0ll) ? 0ll : a / x);
	ans += ((y == 0ll) ? 0ll : a / y);
	ans -= ((l == 0ll) ? 0ll : a / l);
	return ans;
}

int main(){
	LL a, b, x, y,z, ans;
	while (cin >> a >> b >> x >> y){
		int zero = ((a<0ll && b>0ll) || (a == 0ll) || (b == 0ll));
		x = abs(x); y = abs(y);z = lcm(x, y);
		if (a == 0ll && b>0ll) a++;
		if (b == 0ll && a<0ll) b--;
		if (a<0ll && b<0ll)
			ans = amb(-a, x, y, z) - amb(-b - 1, x, y, z) + zero;
		else if (a>0ll && b>0ll)
			ans = amb(b, x, y, z) - amb(a - 1, x, y, z) + zero;
		else
			ans = amb(b, x, y, z) + amb(-a, x, y, z) + zero;
		printf("%lld\n", ans);
	}
}