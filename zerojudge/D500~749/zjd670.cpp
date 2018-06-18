#include <iostream>
#include <string>
using namespace std;
int n[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

int main(){
	string a;
	while (cin >> a){
		for (int i = 0, len = a.size(); i < len; i++){
			if ((a[i] >= 'A') && (a[i] <= 'Z'))cout << int(n[a[i] - 'A']);
			else cout << a[i];
		}
		cout << endl;
	}
}