#include <iostream>
using namespace std;

int main(){
	long double h, n, m, t, a, b, c;
	while (cin >> n >> m >> t){
		h = 0;
		for (int i = 0; i < t; i++){
			cin >> a >> b >> c;
			h += 7 * c - c * ((!(a-1)) + (!b) + (a == n) + (b == m)+(!(a-1)||!b)+(!(a-1)||b==m)+(a==n||!b)+(a==n||b==m));
		}
		printf("%.2llf\n", h / (n*m));
	}
}