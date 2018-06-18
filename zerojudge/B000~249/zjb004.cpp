#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
	int main(){
		double D, L, r1, r2, area, PI = acos(-1.);
		while (cin >> D >> L){
			r1 = L / 2;
			r2 = sqrt(L*L - D*D) / 2;
			area = PI*r1*r2;
			cout << fixed << setprecision(3) << area << endl;
		}
}