#include <iostream>
using namespace std;
    int main(){
		int a, b, i, mx = 8, mxi = 0;
		for (i = 1; i <= 7; i++){
			cin >> a >> b;
			if (a + b > mx){
				mx = a + b;
				mxi = i;
			}
		}
		cout << mxi << endl;
}