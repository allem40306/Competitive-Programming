#include <iostream>
using namespace std;
#define N 550
int arr[N];

void bulit(){
	arr[0] = 0; 
	arr[1] = 1;
	for (int i = 2; i < N; i++)
		arr[i] = arr[i - 1] + (i - 1);
	return;
}

int main(){
	bulit();
	int n;
	while (cin >> n)
		printf("%d\n", arr[n]);
}