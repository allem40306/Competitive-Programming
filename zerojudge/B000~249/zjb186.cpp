#include <iostream>
using namespace std;

int main(){
	int co, ch, ca,p1,p2;
	while (cin >> co >> ch >> ca){
		p1 = co / 10;
		p2 = ca / 2;
		if (p2 < p1)p1 = p2;
		ch += p1;
		cout << co<<" 個餅乾，"<<ch<<" 盒巧克力，"<<ca<<" 個蛋糕。" << endl;
	}
}