#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {
	int n,m,a;
	double sum;
	cin>>n;
	while(n--){
        cin>>m;
        sum=0;
        for(int i=0;i!=m;i++){
            cin>>a;
            sum+=a;
        }
        cout<<fixed<<setprecision(2)<<sum/m<<endl;
    }
}