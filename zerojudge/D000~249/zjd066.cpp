#include <iostream>
using namespace std;

int main() {
	int m, t, h;
	while (cin >> h >> m){
		t = h * 60 + m;
		cout << ((t < 1020 && t>=450) ? "At School\n" : "Off School\n");
	}
}