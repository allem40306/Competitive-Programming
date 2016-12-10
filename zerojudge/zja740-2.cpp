#include <iostream>
#include <cstdio>
#include <vector>
#define N 20000000
using namespace std;
typedef long long ll;

bool P[N];
vector<int> p;

int main()
{
    fill(P, P+N, true);
 
    for(int i = 2; i < N; i++){
        if( P[i] ) 
        {
            p.push_back(i);
            for(ll j = (ll)i*i; j < N; P[j] = false, j+=i);
        }
    }
    int x; ll sum;
    while( scanf("%d", &x) != EOF ){
        sum = 0;
        for(int pi = 0, pn = p.size(); pi < pn; pi++){
            while( x%p[pi] == 0 ) x /= p[pi], sum += p[pi];
            if( x == 1 ) break;
        }
		if( x == 1 ) printf("%lld\n", sum);
        else printf("%lld\n", sum+x);
    }
}
