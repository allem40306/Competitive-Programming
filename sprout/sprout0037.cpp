#include <iostream>
using namespace std;
#define N 100005
int main(){
	int t,ti=0,x,arr[N],qt=0,qb=0;
	for(cin>>t;ti<t;ti++){
		cin>>x;
		if(x%2){
			cin>>x;
			arr[qt++]=x;
		}else{
			if(qt==qb)cout<<"empty!\n";
			else{
				cout<<arr[qb++]<<endl;
			}
		}
	}
}
