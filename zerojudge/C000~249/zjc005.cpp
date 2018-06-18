#include <iostream>
using namespace std;
int main(){
	long long int n, f, a, b, c, t;
	cin >> n;
	while (n--){
		cin >> f;
		t = 0;
		while (f--){
			cin >> a >> b >> c;
			t = t + a *c;
		}
		cout << t << endl;
	}
}