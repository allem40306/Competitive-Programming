#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	double  n,ax, ay, bx, by, cx, cy;
	int m;
	cin >> n;
	while (n--){
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		m = abs(ax*by - ay*bx + bx*cy - by*cx + cx*ay - cy*ax)/14 + 0.5;
		cout << m << endl;
	}
}
