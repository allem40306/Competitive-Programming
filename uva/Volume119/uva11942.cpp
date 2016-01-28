#include <iostream>
#include <cstdlib>
using namespace std;
int main() {	
	int a[10], m, sum;
	while (cin >> m){
		cout << "Lumberjacks:\n";
		while (m--){
			cin >> a[0];
			sum = 0;
			for (int i = 1; i < 10; i++){
				cin >> a[i];
				if (a[i - 1] < a[i])sum+=1;
				else sum-=1;
			}
			if (sum == 9||sum==-9)cout << "Ordered\n";
			else cout << "Unordered\n";
		}
	}
}