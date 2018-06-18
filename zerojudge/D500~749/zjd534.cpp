#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
	int n[4] = { 0, 1, 2, 3 }, a1, a2, a3, a4,f;
	while (cin  >> a1 >> a2 >> a3 >> a4){
		f = 0;
		do{
			if (  n[0] + n[1]==a1 &&  n[2] + n[3]==a2  && 
				n[0] + n[2] ==a3  && n[1] + n[3] ==a4 ){
				cout<< n[0] << " " << n[1] << endl;
				cout<< n[2] << " " << n[3] << endl;
				f = 1;
				break;
			}
		} while (next_permutation(n, n+4));
		if (f == 0)cout << "No solutions.\n";
	}
}