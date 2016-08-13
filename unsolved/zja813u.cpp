#include <iostream>
#include <algorithm>
using namespace std;
#define N 10000 //1000000
#define max(x,y) x>y?x:y

int main(){
	int h[N], top[N], see[N], n, tr = 0;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){cin >> h[i]; see[i] = 0;}
	top[0] = 1;
	for (int j = 1; j < n; j++){
		if (h[j]>h[top[tr]]){
			see[top[tr]] = j - top[tr];
			top[++tr] = j;
		}
	}
	for (int i = 0; i < n; i++){
		ans += see[i];
	}
	cout << ans*2 << endl;
}