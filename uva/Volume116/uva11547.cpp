#include <iostream>
#include <cstdio>
using namespace std;
#define max(x,y) x>y?x:y

int main(){
	int t,n;
	cin >> t;
	while (t-- ){
		cin >> n;
		n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
		printf("%d\n", (n / 10) % 10 * (n > 0 ? 1 : -1));
	}
}