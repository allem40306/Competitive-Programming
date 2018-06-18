#include <iostream>
#include <stack>
using namespace std;
#define N 2000000

struct buliding{
	int h, s;
	buliding(int x, int y) :h(x), s(y){}
};
int main() {
	int n, h[N];
	while (cin >> n){
		for (int i = 0; i < n; i++)cin >> h[i];
		long long ans = 0;
		stack <buliding> st;
		for (int i = 0; i < n; i++){
			long long see = 0;
			while (!st.empty() &&h[i]>st.top().h)
				see += st.top().s, st.pop();
			if (!st.empty() && h[i] == st.top().h)
				see += st.top().s, st.top().s++;
			else
				st.push(buliding(h[i], 1));
			if (st.size()>1)see++; //算進最前面的
			ans += see;
		}
		printf("%lld\n", ans*2);
	}
}