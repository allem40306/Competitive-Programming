#include <iostream>
using namespace std;
int main(){
	int n, w, h, mx, s4, p, p1;
	while (cin >> n, n){
		p = 1;
		p1 = 0;
		s4 = 0;
		mx = 0;
		while (n--){
			cin >> w >> h;
			if (w > h) swap(w, h);
			if (h <= 2 * w)s4 = w * 2;
			if (h > 2 * w && h < 4 * w)s4 = h;
			if (h >= 4 * w)s4 = w * 4;
			if (s4 > mx){
				mx = s4;
				p1 = p;
			}
			p++;
		}
		cout << p1 << endl;
	}
}
