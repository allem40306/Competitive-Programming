#include <iostream>
using namespace std;
#define L 20000


int main(){
	int n;
	while (cin >> n){
		int arr[L], ans = 0;
		for (int i = 0; i < n; i++)cin >> arr[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				ans += (arr[j]>arr[i]);
		printf("%d\n",ans);
	}
}