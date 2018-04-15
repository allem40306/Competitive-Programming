#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
	int n, arr[10];
	float ap = 0, t = 0;
	memset(arr, 0, sizeof(arr));
	while (cin >> n, n){
		arr[n]++;
		ap++;
	}
	for (int i = 5; i; i--){
		printf("%d (", i);
		if (arr[i] / 10 == 0)cout << ' ';
		printf("%d) |", arr[i]);
		t += arr[i] * i;
		for (int j = 0; j < arr[i]; j++)
			printf("=");
		printf("\n");
	}
	printf("Average rating: ");
	cout << fixed << setprecision(4) << t / ap << endl;
}