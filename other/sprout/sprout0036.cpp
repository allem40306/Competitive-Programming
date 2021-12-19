#include <iostream>
using namespace std;
#define N 100005
int main(){
	int t,ti=0,x,arr[N],stt=-1;
	for(cin>>t;ti<t;ti++){
		cin>>x;
		if(x%2){
			cin>>x;
			arr[++stt]=x;
		}else{
			if(stt==-1)cout<<"empty!\n";
			else{
				cout<<arr[stt--]<<endl;
			}
		}
	}
}
