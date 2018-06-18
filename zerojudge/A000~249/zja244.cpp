#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	long long int a, b, c,n;
	cin >> n;
	for (int x=0; x < n; x++){
		cin >> a >> b >> c;
		if (a == 1)cout << (b + c)<<endl;
		else if (a == 2)cout << (b - c) << endl;
		else if (a == 3)cout << (b * c) << endl;
		else cout << (b / c) << endl;
	}
}
