#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

bool jo(int k, int n){
	int s = 0;
	for (int i = k*2; i >k; i--){
		s = (s + n) % i;
		if (s < k)return 0;
	}
	return 1;
}


int main(){
	int m, k;
	while (cin >> k, k){
		for (int i = 1;; i++){
			if (jo(k, i)){
				printf("%d\n",i+1);
				break;
			}
		}
	}
}