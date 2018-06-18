#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const double pi = acos(-1.0);
#define m(a) a*a

int main(){
	double f;
	while (cin >> f){
		f = acos(asin(f));
		f = f * 180 / pi;
		if(f>=0.0)cout << fixed << setprecision(2) << f << endl;
		else printf("FAIL!\n");
	}
}