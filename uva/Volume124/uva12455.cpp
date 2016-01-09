#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, p, steps[20], pos[1001] = { 1 };
		cin >> n >> p;
		for (int i = 0; i < p; i++)cin >> steps[i];
		for (int j = 0; j < p; j++)
			for (int k = n; k >= steps[j]; k--)
				pos[k] += pos[k - steps[j]];
		if (pos[n])cout << "YES\n";
		else cout << "NO\n";
	}
}