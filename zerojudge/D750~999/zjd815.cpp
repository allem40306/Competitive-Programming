#include <iostream>
#include <algorithm>
using namespace std;
#define N 61
int main(){
	int n, m;
	while (cin >> n >> m){
		printf(n == m ? "= =\"\n" : ">\\\\\\<\n");
	}
}