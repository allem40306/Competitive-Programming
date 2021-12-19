#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 105
#define M 100005
struct Node{
    int value,r,next;
    Node(): next(-1) {}
};
int main(){
    int n,m,x,y,pr=-1,en[N];
    string s;
    Node head[N],p[M];
    memset(en,-1,sizeof(en));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        if(s[0]=='A'){
            cin>>x>>y;
            p[++pr].value=y;
            if(en[x]!=-1)p[en[x]].next=pr;
            else head[x].next=pr;
            en[x]=pr;
        }else if(s[0]=='L'){
            cin>>x;
            if(en[x]==-1)
                printf("queue %d is empty!\n",x);
            else{
                head[x].next=p[head[x].next].next;
                if(head[x].next==-1)en[x]=-1;
            }
        }else{
            cin>>x>>y;
            if(en[x]==-1)continue; 
            if(en[y]!=-1)
                p[en[y]].next=head[x].next;
            else
                head[y].next=head[x].next;
            en[y]=en[x];
			head[x].next=en[x]=-1;     
        }
    }
        for(int i=1;i<=n;i++){
            printf("queue %d:",i);
            if(en[i]==-1){
                printf(" empty\n");
                continue;
            }
            for(int j=head[i].next;j!=-1;j=p[j].next){
                cout<<' '<<p[j].value;
            }
            cout<<endl;
        }
}
