#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int  sum[101],s, n;
	for (int j = 0; j < 102; j++){
		sum[j] = 0;
	}
	while (cin >> s){
		if (s>=0){
			cin >> n;
			sum[s] += n;
		}
	}
	for (int i = 0; i < 101; i++){
		if (sum[i])cout << i << " " << sum[i] << endl;
	}
}