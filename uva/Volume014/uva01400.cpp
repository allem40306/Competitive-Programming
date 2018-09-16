#include <bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long LL;
typedef pair<int,int> PII;
#define Lc(x) (x<<1)
#define Rc(x) ((x<<1)+1)
#define MP make_pair
//#define debug
struct Node{
    int L,R;
    int pre,suf;
    PII p;
}node[2*N];

LL s[N];

inline LL get_sum(PII a){
    return s[a.second]-s[a.first-1];
}

bool is_max(PII a,PII b){
    LL sa=get_sum(a),sb=get_sum(b);
    if(sa!=sb)return sa>sb;
    return a<b;
}

PII maxp(Node a,Node b){
    PII ans;
    if(is_max(a.p,b.p))ans=a.p;
    else ans=b.p;
    if(is_max(MP(a.suf,b.pre),ans))ans=MP(a.suf,b.pre);
    return ans;
}

int maxpre(Node a,Node b){
    if(is_max(MP(a.L,a.pre),MP(a.L,b.pre)))return a.pre;
    return b.pre;
}

int maxsuf(Node a,Node b){
    if(is_max(MP(a.suf,b.R),MP(b.suf,b.R)))return a.suf;
    return b.suf;
}

Node push(Node a,Node b){
    Node ans;
    ans.L=a.L;
    ans.R=b.R;
    ans.p=maxp(a,b);
    ans.pre=maxpre(a,b);
    ans.suf=maxsuf(a,b);
    return ans;
}

void bulid(int L,int R,int x){
    if(L==R){
        node[x].L=L;
        node[x].R=R;
        node[x].pre=node[x].suf=L;
        node[x].p=MP(L,L);
        return;
    }
    int M=(L+R)>>1;
    bulid(L,M,Lc(x));
    bulid(M+1,R,Rc(x));
    node[x]=push(node[Lc(x)],node[Rc(x)]);
    return;
}

Node query(int L,int R,int x){
    #ifdef debug
        printf("%d %d %d->[%d,%d]\n",L,R,x,node[x].L,node[x].R);
    #endif // debug
    if(L<=node[x].L&&node[x].R<=R)return node[x];
    int M=(node[x].L+node[x].R)>>1;
    if(L<=M&&M<R)return push(query(L,R,Lc(x)),query(L,R,Rc(x)));
    if(L<=M)return query(L,R,Lc(x));
    return query(L,R,Rc(x));
}

int main(){
    int n,m,a,b,ti=1;
    while(cin>>n>>m){
        cout<<"Case "<<ti++<<":\n";
        for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
        }
        bulid(1,n,1);
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            Node ans=query(a,b,1);
            cout<<ans.p.first<<' '<<ans.p.second<<'\n';
        }
    }

    return 0;
}
