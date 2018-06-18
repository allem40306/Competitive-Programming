#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int nn = n, t = 0;
		for (int i = 0; i < 100; i++){
			while (nn){
				t += (nn % 10)*(nn % 10);
				nn /= 10;
			}
			nn = t;
			if (nn == 1)break;
			t = 0;
		}
		if (nn == 1)printf("%d is a happy number\n", n);
		else printf("%d is an unhappy number\n", n);
	}
}