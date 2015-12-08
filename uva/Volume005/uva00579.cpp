#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int main(){
	char s;
	int a, b;
	float m, n;
	while (cin >> a >> s >> b, a + b != 0){
		m = a * 30 - b*5.5;
		if (m < 0)m = m + 360;
		if (m > 180)m = 360 - m;
		cout << fixed << setprecision(3) << m << endl;
	}
}