#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int prime(int n){
	if(n<=1)return 0;
	int m=floor(sqrt(n)+0.5);
	for (int i=2;i<=m;i++)
	if(n%i==0)return 0;
	return 1;
}

int main(){
   int a,b,sum;
   while(cin>>a>>b){
   sum=0;     
   for(int i=a;i<=b;i++)
      sum+=prime(i);      
      cout<<sum<<endl;
      } 
}
