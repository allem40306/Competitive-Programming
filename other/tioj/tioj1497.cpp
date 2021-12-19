#include <bits/stdc++.h>
using namespace std;
#define P for(int i(0);i<n;i++){printf("%d\n",sa[i]);}
constexpr int sizz(2000514U);
bool not_equ(int*ra,int a,int b,int k,int n){
	return ra[a]!=ra[b]||a+k>=n||b+k>=n||ra[a+k]!=ra[b+k];
}
void radix(int*box,int*key,int*it,int*ot,int m,int n){
	fill_n(box,m,0);
	for(int i(0);i<n;i++)box[key[i]]++;
	partial_sum(box,box+m,box);
	for(int i(n-1);i>=0;i--)ot[--box[key[it[i]]]]=it[i];
}
void make_sa(int*sa,int*ra,const char*s,int n){
	static int box[sizz],tp[sizz];
	copy_n(s,n,ra);
	int k(1),m(256);
	do{
		iota(tp,tp+k,n-k);
		iota(sa+k,sa+n,0);
		radix(box,ra+k,sa+k,tp+k,m,n-k);
		radix(box,ra+0,tp+0,sa+0,m,n-0);
		tp[sa[0]]=0,m=1;
		for(int i(1);i<n;i++){
			m+=not_equ(ra,sa[i],sa[i-1],k,n);
			tp[sa[i]]=m-1;
		}
		copy_n(tp,n,ra);
		k*=2;
	}while(k<n&m!=n);
}
int t,ti=0,sa[sizz],ra[sizz];
char s[sizz];
int main(){
	gets(s);
	int n=strlen(s);
	make_sa(sa,ra,s,n);
	P
}
