#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t1, t2, t3, t4,sum;;
	while (cin>>t1>>t2>>t3>>t4){
		sum = t3 + t4;
		t1 -= 37 * t3;
		sum += ceil(t2 / 8.0);
		if (t1 > 0)sum += ceil(t1 / 64.0);
		cout <<sum << endl;
	}
}