#include <iostream>
using namespace std;

int main(){
    int n,m;
    freopen("b916_00.in","r",stdin);
	freopen("b916_00.out","w",stdout); 
    cin>>m;
    for(int i=0;i<m;i++){
            cin>>n;
            n=(n/3)*3;
            cout<<(3+n)*(n/3)/2<<'\n';
    }
} 
