#include<iostream>
#include <algorithm>
#include "interactive/23.h"
using namespace std;
const int N = 100005;

int main()
{
	int n, in[N];
	GetN(n);
	Get(in[0]);
	for (int i = 1; i < n; i++)
	{
		Get(in[i]);
		in[0]=__gcd(in[0],in[i]);
		Report(in[0]);
	}
	Bye();
}