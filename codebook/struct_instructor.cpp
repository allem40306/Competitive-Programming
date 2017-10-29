#include <bits/stdc++.h>
using namespace std;

struct Loc{
	int x,y;
	Loc(int x,int y):x(x),y(y){
	}
	Loc &operator =(const Loc &b){
		x=b.x;
		y=b.y;
		return *this;
	}
	Loc &operator *(const int &b){
		x*=b;
		y*=b;
		return *this;
	}
	Loc &operator *(const int* &b){
		x*=*b;
		y*=*b;
		return *this;
	}
};

int main(){
	Loc a=Loc(0,0);
	int x=1;
	int *y=&x;
	a=a*x;
	a=a*y;
}
