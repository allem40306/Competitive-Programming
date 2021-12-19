#include <iostream>
#include <functional>
#include <queue>
using namespace std;
int t[6],ans,us;
bool init(){
	bool b=0;
	for(int i=0;i<6;i++){
		cin>>t[i];
		if(t[i])b=1;
	}
	return b;
}
int main(){
	cin.tie(NULL);
	while(init()){
		ans=t[3]+t[4]+t[5]; //4 5 6
		us=t[3]*20+t[4]*11;
		us-=4*min(t[1],t[3]*5); //2->4
		t[1]-=min(t[1],t[3]*5);
		ans+=(t[2]/4)+(t[2]%4>0); //3
		t[2]%=4;
		if(t[2]==1){ //2->3
			us+=36-(9+4*min(t[1],5));
			t[1]-=min(t[1],5);
		}else if(t[2]==2){
			us+=36-(18+4*min(t[1],3));
			t[1]-=min(t[1],3);
		}else if(t[2]==3){
			us+=36-(27+4*min(t[1],1));
			t[1]-=min(t[1],1);
		}
		if(t[1]%9)us+=4*(9-t[1]%9);//2
		ans+=(t[1]/9)+(t[1]%9>0); 
		t[1]%=9;
		t[0]-=min(t[0],us); //1->23456
		ans+=(t[0]/36)+(t[0]%36>0);//1
		cout<<ans<<'\n';
	}
}
