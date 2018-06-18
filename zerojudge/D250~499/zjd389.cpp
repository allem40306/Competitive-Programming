#include <iostream>
using namespace std;
#define N 80
int endd[N] = { 0, 1, 2, 2 };

void dp(){
	for (int i = 4; i <= 76; i++){
		endd[i] = endd[i - 2] + endd[i - 3];
	}
}

int main(){
	dp();
	int n;
	while (cin >> n)
		cout << endd[n] << endl;
}