#include <iostream>
#include <algorithm>
using namespace std;

struct nn{
	int i, n;
}arr[10];

void init(){
	for (int i = 0; i < 10; i++){
		arr[i].i = i;
		arr[i].n = 0;
	}
	return ;
}

bool cmp(nn a, nn b){
	if (a.n != b.n)return a.n > b.n;
	return a.i < b.i;
}

int main(){
	int t, n;
	while (cin >> t){
		init(); int uz = 0;
		for (int i = 0; i < t; i++){ cin >> n; arr[n].n++; }
		sort(arr, arr + 10, cmp);
		for (int i = 0; i < 10; i++){
			if (!arr[i].n)continue;
			if (uz++)printf(" ");
			printf("%d", arr[i].i);
		}
		printf("\n");
	}
}