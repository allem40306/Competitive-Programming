#include <iostream>
#include <cmath>
using namespace std;
const int N=100005;
int n,q,a[N],l,x,y;
struct Node{
    long long ma,add,cha;//change
    Node *lc,*rc;
    Node():ma(0),add(0),cha(0),lc(NULL),rc(NULL){}
    void pull(){
        ma=max(lc->ma,rc->ma);
    }
    void cha_push(){
        lc->cha=rc->cha=cha;
        lc->add=rc->add=0;
        cha=0;
    }
    void add_push(){
        lc->add+=add;
        rc->add+=add;
        add=0;
    }
};

Node* bulid(int L,int R){
//    cout<<L<<' '<<R<<'\n';
    Node *node=new Node();
    if(L==R){
        node->ma=a[L];
        return node;
    }
    int M=(L+R)>>1;
    node->lc=bulid(L,M);
    node->rc=bulid(M+1,R);
    node->pull();
    return node;
}

void cha(Node *node,int a,int b,int x,int y,int v){
    if(y<a||b<x)return;
    if(x<=a&&b<=y){
        node->ma=v;
        return;
    }
    int M=(a+b)>>1;
    node->cha_push();
    cha(node->lc,a,M,x,y,v);
    cha(node->rc,M+1,b,x,y,v);
    node->pull();
    return;
}

void add(Node *node,int a,int b,int x,int y,int v){
    if(y<a||b<x)return;
    if(x<=a&&b<=y){
        if(node->cha){
            node->ma=node->cha;
            node->cha=0;
        }
        node->ma+=v;
        return;
    }
    int M=(a+b)>>1;
    node->add_push();
    add(node->lc,a,M,x,y,v);
    add(node->rc,M+1,b,x,y,v);
    node->pull();
    return;
}

long long que(Node *node,int a,int b,int x,int y){
    if(y<a||b<x)return 0;
    if(x<=a&&b<=y){
        return node->ma;
    }
    int M=(a+b)>>1;
    if(node->cha)node->cha_push();
    if(node->add)node->add_push();
    return max(que(node->lc,a,M,x,y),que(node->rc,M+1,b,x,y));
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    Node *root=bulid(1,n);
    for(int i=0;i<q;i++){
        cin>>l;
        if(l==1){
            cin>>l>>x>>y;
            root->add=y;
            add(root,1,n,l,x,y);
        }else if(l==2){
            cin>>l>>x;
            cout<<que(root,1,n,l,x)<<'\n';
        }else{
            cin>>l>>x>>y;
            root->cha=y;
            cha(root,1,n,l,x,y);
        }
    }
}
