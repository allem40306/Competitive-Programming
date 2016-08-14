#include <iostream>
#include <string>
using namespace std;
#define N 30

int main(){
	int n, k, arr[N], ii;
	string s, t;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> ii;
			arr[ii - 1] = i;
	}
		cin >> s >> k;
		for (int j = 0; j < k; j++){
			t = s;
			for (int i2 = 0; i2 < n; i2++){
				s[arr[i2]] = t[i2];
			}
		}
		cout << s << endl;
	}
}