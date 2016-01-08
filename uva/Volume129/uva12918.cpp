#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,m, t, i;
	long long sum;
	for (cin >> t, i = 0; i < t; i++){
		sum = 0;
		cin >> n >> m;
		while (n--)sum += --m;
		printf("%d\n", sum);
	}
}