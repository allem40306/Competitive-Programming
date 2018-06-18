#include <iostream>
using namespace std;

int main(){
    int s[3],e[3];
    for(int i=0;i<3;i++){
        cin>>s[i]>>e[i];
    }
    if(e[0]>s[1]||e[1]>s[2]){
        cout<<"QQ\n";
    }else{
        cout<<"Happy\n";
    }
}
