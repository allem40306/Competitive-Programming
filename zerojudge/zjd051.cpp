#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int f;
	cin >> f;
	cout << fixed << setprecision(3) << (f - 32)*5. / 9;
}