#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int n, c, k, i = 1;
	while (cin >> n, n > 0){
		c = 0, k = n;
		if (k > 1){
			while (k)c++, k /= 2;
			if (int(pow(2,c))/n==2)c--;
		}
		cout << "Case " << i << ": " << c << endl;
		i++;
	}
}
