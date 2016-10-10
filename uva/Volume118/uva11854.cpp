#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3];
	while (scanf("%d %d %d", &a[0], &a[1], &a[2])){
		if (!a[0] && !a[1] && !a[2])break;
		sort(a, a + 3);
		printf((a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) ? "right\n" : "wrong\n");
	}
}