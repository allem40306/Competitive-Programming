#include <iostream>
using namespace std;
const int N=35;
int main(){
    char ch[4];
    long long x=0,y;
    for(int i=0;i<4;i++){
        cin>>ch[i];
        cout<<ch[i]<<":\n"<<int(ch[i])<<" =";
        y=(int)ch[i];
        for(int j=31;j>=0;j--){
            if(j%8==7)cout<<' ';
            cout<<((y>>j)&1);
        }
        cout<<'\n';
        x=x*(1<<8)+int(ch[i]);
    }
    cout<<"\'"<<ch[0]<<"\' and \'"<<ch[1]<<"\' and \'"<<ch[2]<<"\' and \'"<<ch[3]<<"\' packed in an unsigned int:\n";
    cout<<x<<" =";
    for(int i=31;i>=0;i--){
        if(i%8==7)cout<<' ';
        cout<<((x>>i)&1);
    }
        cout<<'\n';
}
