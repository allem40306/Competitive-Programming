#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 200

int main(){
	int n, h, m;
	char ch;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> h >> ch >> m;
			h = (h + ((m + 1) / 60)) % 24, m = (m + 1) % 60;
			while (1){
				if (h == 0){if(m / 10 == 0 || m % 10 == m / 10)break; }
				else if (h / 10 == 0){if(m % 10 == h)break; }
				else if (h / 10 == m % 10 && m / 10 == h % 10)break;
				h = (h + ((m + 1) / 60)) % 24, m = (m + 1) % 60;
			}
			if (h < 10)printf("0");
			cout << h << ch;
			if (m < 10)printf("0");
			cout << m << endl;
		}
	}
}