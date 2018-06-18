#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,b,c,t,d;
    while(cin>>t){
    for(int i=0;i<t;i++){
    	cin>>a>>b>>c;
    	d = b*b - 4 * a*c;
		if (sqrt(d)!=ceil(sqrt(d))||d<0)
			cout<< "No\n";
			else
			cout<<"Yes\n";
		}
 	cout<<"\n";
	}
	return 0; 
}