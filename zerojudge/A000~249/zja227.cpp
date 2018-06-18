#include<iostream>
using namespace std;

void out(int n, int from, int to){
	if (n>1)out(n - 1, from, 3 - from - to);
	cout<<"Move ring "<<n <<" from "<<char ('A' + from)<<" to "<<char('A' + to)<<endl;
	if (n>1)out(n - 1, 3 - from - to, to);
}

int main(){
	int n;
	while (cin>>n){
		out(n, 0, 2); 
		cout << endl;
	}
}