#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int m, a, b, sum, ca = 1;
	cin >> m;
	while (m--){
		sum = 0;
		cin >> a>> b;
		for (int i = a; i <= b; i++)
			if (sqrt(i) == floor(sqrt(i)))sum += i;
		cout <<"Case "<<ca<<": "<<sum << endl;
		ca++;
	}
}
