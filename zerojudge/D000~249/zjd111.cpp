#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int n;
	while (cin >> n,n){
		if (sqrt(n)== floor(sqrt(n)))cout << "yes" << endl; 
		else cout << "no" << endl;
	}
}
