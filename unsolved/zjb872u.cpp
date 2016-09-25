#include <iostream>
#include <map>
using namespace std;
#define MP make_pair
struct line{
	int x, y;
	line(int x, int y) :x(x), y(y){}
};
map <line, int> ma;
map <line, int>::iterator it;


	int gcd(int a, int b){
	if (!a || !b)return 0;
	int r;
	while (r = a%b){ a = b; b = r; }
	return b;
}

void bulit(int a, int b){
	int g;
	if (a<0 && b<0){
		g = gcd(-1 * a, -1 * b);
		ma[line(-1 * a / g, -1 * b / g)]++;
	}
	else if (a < 0 || b < 0){
		if (b < 0){
			g = gcd(a, -1 * b);
			ma[line(-1 * a / g, -1 * b / g)]++;
		}
		else{
			g = gcd(-1 * a, b);
			ma[line(a / g, b / g)]++;
		}
	}
	else{
		g = gcd(a, b);
		ma[line(a / g, b / g)]++;
	}
	return;
}


int main() {
	int t, ti = 0, n, a, b, x, y;
	for (cin >> t; ti < t; ti++) {
		cin >> n >> a >> b;
		ma.clear();
		for (int ni = 1; ni < n; ni++){
			cin >> x >> y;
			bulit(x - a, b - y);
		}
	}
}