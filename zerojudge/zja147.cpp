#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, i;
	while (cin >> n,n){
		for (i = 0; i < n; i++)
			if (i % 7)cout << i << ' ';
		cout << endl;
	}
}
