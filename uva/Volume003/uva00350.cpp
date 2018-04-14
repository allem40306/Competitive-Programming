#include <bits/stdc++.h>
using namespace std;

int main(){
    int z,i,m,l,ti=1,pos[100005];
    while(cin>>z>>i>>m>>l,z||i||m||l){
        int length=0;
        memset(pos,0.,sizeof(pos));
        while(!pos[l]){
            length++;
            pos[l]=length;
            l=(z*l+i)%m;
        }
        cout<<"Case "<<ti++<<": "<<length-pos[l]+1<<'\n';
    }
}
