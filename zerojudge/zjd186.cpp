#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	while (cin >> a >> b){
		if (a == 0 && b == 0)break;
		else if(sqrt(a)==floor(sqrt(a)))
			cout << int(sqrt(b)) - int(sqrt(a)) + 1 << endl;
		else cout << int(sqrt(b)) - int(sqrt(a))  << endl;
	}
}
