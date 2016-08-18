#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long x, h;
	while(cin >> x){
		h = sqrt(x * 2);
		while (1){
			if (!h||2 * x / h == h + 1){
				cout << h << endl;
				break;
			}
			h++;
		}
	}
}