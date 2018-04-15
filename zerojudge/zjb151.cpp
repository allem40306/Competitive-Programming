#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
	priority_queue <int, vector <int>, greater<int>>q;
	int n, x, e = 0;
	cin >> n;
	while (n--)
		cin >> x, q.push(x);
	while (q.size() >1){
		x = q.top(), q.pop();
		x += q.top(), q.pop();
		q.push(x);
		e += x;
	}
	cout << e << endl;
}