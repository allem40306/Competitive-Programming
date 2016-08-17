#include <iostream>
using namespace std;
#define N 100000
int bag[N], arr[N];

void init(){
	for (int i = 0; i < N; i++)
		bag[i] = 0;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		for (int ni = 0; ni < n; ni++){
			int mm, sum = 0;
			init();
			for (int mi = 0; mi < m; mi++){
				cin >> arr[mi];
				sum += arr[mi];
			}
			for (int i = 0; i < m; i++)
				for (int j = sum; j - arr[i] >= 0; j--)
					if ((bag[j - arr[i]] + arr[i] > bag[j]) && (bag[j - arr[i]] + arr[i] <= sum))
						bag[j] = bag[j - arr[i]] + arr[i];
			if (!(sum % 2) && bag[sum / 2] == sum / 2)printf("Yes\n");
			else printf("No\n");
		}
	}
}