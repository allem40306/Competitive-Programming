#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int sod(int i){int r=0;for(;i;i/=10)r+=i%10;return r;}

int fun(int a, int b) {
    int ans = 0;
    int i, j, cnt;
    for(i=a; i<=b; i++) {
        cnt = 0;
        for(j=1; j<=i; j++) {
            if( j + sod(j) == i ) cnt++;
        }
        if( cnt == 0 ) ans++;
    }
    return ans;
}

int fun(int a) {
    int i;
    for(i=1; i<=a; i++){
        if( i + sod(i) == a ){
            return i;
        }
    }
    return -1;
}

int main(){
	int ni=1,n,a,b;
	string s;
	for(cin>>n>>ws;ni<=n;ni++){
		getline(cin,s);
		istringstream ss(s);
		ss>>a;
		printf("Case %d: ",ni);
		if(ss>>b)printf("%d\n",fun(a,b));
		else printf("%d\n",fun(a));
	}
} 
