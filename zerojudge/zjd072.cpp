#include <iostream>
using namespace std;
    int main(){
	int a, y, leap = 0,n,m=0;
	cin >> n;
	while (n--){
		cin >> y;
		m++;
		if ((y % 4 == 0 && y % 100) || y % 400 == 0)
			cout << "Case"<<" " << m <<": "<< "a leap year" << endl;
		else cout << "Case" << " " << m << ": " << "a normal year" << endl;
	}
}