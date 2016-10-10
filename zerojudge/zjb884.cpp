#include <iostream>
using namespace std;

int main() {
	int n, x, y, yee;
	cin >> n;
	while (n--){
		cin >> x >> y;
		yee = 100 - x - y;
		if (0 < yee&&yee <= 30)printf("sad!\n");
		else if (30 < yee&&yee <= 60)printf("hmm~~\n");
		else if (60 < yee&&yee < 100)printf("Happyyummy\n");
		else printf("evil!!\n");
	}
}