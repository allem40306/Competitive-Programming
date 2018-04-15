#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n){
		printf(n % 4 ? "fat\n": "egg\n");
	}
}