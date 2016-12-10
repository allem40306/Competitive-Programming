#include <iostream>
using namespace std;
int main(){
	int n;
	cin>> n;
	if (n <= 10)cout << 6 * n;
	else
		if (n > 10 && n <= 20)cout << 60 + (2 * (n - 10));
		else
			if (n > 20 && n <= 40)cout << 80 + (1 * (n - 20));
			else
				if (n > 40)cout << 100;

}
