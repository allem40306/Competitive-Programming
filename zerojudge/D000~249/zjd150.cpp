#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t,n,i,p[20000],d;
	cin >> t;
	while (t--){
		d = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> p[i];
		}
		sort(p, p + n);
		for (int i = n - 3; i >= 0; i -= 3)
			d += p[i];
		cout << d << endl;
	}
}
