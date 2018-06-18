#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a, f, n;
	cin >> n >> ws;
	for (int nn = 0; nn < n; nn++){
		cin >> ws;
		cin >> a >> f;
		int i = 1, j = 1;
		for (i = 1; i <= f; i++){
			for (j = 1; j <= a; j++){
				int j2 = j;
				while (j2--)cout << j;
				cout << endl;
			}
			for (j -= 2; j; j--){
				int j3 = j;
				while (j3--)cout << j;
				cout << endl;
			}
			cout << endl;
		}
	}
}