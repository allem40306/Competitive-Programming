#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define S 100005

int main() {
	int tc, t = 1;
	cin>>tc;
	while (tc--){
		int n,m[S],p;
		cin>>n;
		for(p=0;p<n;p++)cin>>m[p];
		int lis[S] = { 1 };
		int maxx = 1;
		for (int i = 1;i <= p;i++) {
			for (int j = 0;j < i;j++)
				if (m[i] > m[j])lis[i] = max(lis[i], lis[j] + 1);
			maxx = max(maxx, lis[i]);
		}
		int oo[S],mm=maxx;
		p--;
		
		for(int o=0;p>=0&&maxx>=0;p--){
			if(lis[p]==maxx){
				oo[maxx]=m[p];
				maxx--;
			}	
		}
		for(int o=1;o<=mm;o++){
			if(o>1)printf(" ");
			printf("%d",oo[o]);
		}
		cout<<endl;
	}
}
