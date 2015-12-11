#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define L 60
int arr[L], buf[L];

int sol(int left, int right){
	if (right - left <= 1)return 0;
	int middle = (right + left) / 2;
	int ans = sol(left, middle) + sol(middle, right);
	int i = left, j = middle, k = left;
	while (i < middle || j < right){
		if (i >= middle)
			buf[k]=arr[j++];
		else if (j >= right)
			buf[k] = arr[i++];
		else {
			if (arr[i]<arr[j])
				buf[k] = arr[i++];
			else{
				buf[k] = arr[j++];
				ans += middle - i;
			}
		}
		k++;
	}
	for (int k = left; k < right; k++)
		arr[k] = buf[k];
	return ans;
}

int main(){
	int n; 
	for (cin >> n; n; n--){
		memset(arr, 0, sizeof(arr));
		memset(buf, 0, sizeof(buf));
		int len; 
		cin >> len;
		for (int i = 0; i < len; i++)cin >> arr[i];
		sol(0, len)£µ
	}
}