#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, s[1000], i;
	while (cin >> n){
		for (i = 0; i < n; i++)
			cin >> s[i];
		sort(s, s + n);
		for (i = 0; i < n; i++)
			cout << s[i] << ' ';
		cout << endl;
	}
}
