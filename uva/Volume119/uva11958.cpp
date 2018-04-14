#include <iostream>
using namespace std;

int main(){
	int t, ti = 1;
	for (cin >> t; ti <= t; ti++){
		int k,h,m,ans=10000,cur,arr,sum;
		char ch;
		cin >> k >> h >> ch >> m ;
		cur=h*60+m;
		for (int i = 0; i < k; i++){
            cin >> h >> ch >> m ;
			arr=h*60+m;
			if(arr<cur)arr+=1440;
			cin>>m;
			sum=arr+m-cur;
			if(sum < ans)ans = sum;
		}
		printf("Case %d: %d\n", ti, ans);
	}
}
