#include <iostream>
using namespace std;
int n,m,t;

void nim(int a,int b,int p){
    if(!b||a/b>1||a==b){
        printf("%s wins\n", p == 0? "Stan" : "Ollie");
		return;
    }
    nim(b,a%b,!p);
}

int main() {
    while(cin>>n>>m,n){
        if(n<m)t=m,m=n,n=t;
        nim(n,m,0);
    }
}
