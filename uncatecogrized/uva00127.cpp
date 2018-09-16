#include <bits/stdc++.h>
using namespace std;
const int N=60;
struct Card{
	char s,r;//suit,rank
};

int main(){
	Card x;
	stack<Card>st[N];
	while(cin>>x.s&&x.s!='#'){
		cin>>x.r;
	}
}