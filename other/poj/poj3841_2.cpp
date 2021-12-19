#pragma GCC optimize(2)
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e6 + 5;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
struct Node
{
    int key, val;
    int h;
    int bf;
    Node *Lc, *Rc;
};

class AVLTree
{
  private:
    Node *root;

  public:
    void init() { root = NULL; }
    int height(Node *T) { return (T) ? (T->h) : 0; }
    int bf(Node *T) { return height(T->Lc) - height(T->Rc); }
    void pull(Node *T)
    {
        T->h = max(height(T->Lc), height(T->Rc)) + 1;
        T->bf = bf(T);
    }
    void balance(Node *&T)
    {
        if (T->bf > 1 && T->Lc->bf > 0)
        {
            T = LL_rotate(T);
        }
        if (T->bf > 1 && T->Lc->bf < 0)
        {
            T = LR_rotate(T);
        }
        if (T->bf < -1 && T->Rc->bf > 0)
        {
            T = RR_rotate(T);
        }
        if (T->bf < -1 && T->Rc->bf > 0)
        {
            T = RL_rotate(T);
        }
    }
    Node *LL_rotate(Node *T)
    {
        Node *B = T->Lc;
        T->Lc = B->Rc;
        B->Rc = T;
        pull(T);
        pull(B);
        return B;
    }
    Node *RR_rotate(Node *T)
    {
        Node *B = T->Rc;
        T->Rc = B->Lc;
        B->Lc = T;
        pull(T);
        pull(B);
        return B;
    }
    Node *LR_rotate(Node *T)
    {
        T->Lc = RR_rotate(T->Lc);
        T = LL_rotate(T);
        return T;
    }
    Node *RL_rotate(Node *T)
    {
        T->Rc = LL_rotate(T->Rc);
        T = RR_rotate(T);
        return T;
    }
    void insert(int key, int val) { insert(root, key, val); }
    void insert(Node *&T, int key, int val)
    {
        if (T == NULL)
        {
            T = (Node *)malloc(sizeof(Node));
            T->bf = 0;
            T->h = 1;
            T->key = key;
            T->val = val;
            T->Lc = T->Rc = NULL;
            return;
        }
        if (key < T->key)
        {
            insert(T->Lc, key, val);
        }
        else
        {
            insert(T->Rc, key, val);
        }
        pull(T);
        balance(T);
    }
    void Find(int flag)
    {
        if (root == NULL)
        {
            printf("0\n");
            return;
        }
        Node *tmp = root;
        if (flag)
        {
            while (tmp->Rc)
            {
                tmp = tmp->Rc;
            }
        }
        else
        {
            while (tmp->Lc)
            {
                tmp = tmp->Lc;
            }
        }
        printf("%d\n", tmp->val);
        Delete(root, tmp->key);
    }
    void Delete(Node *&T, int key)
    {
        if (T == NULL)
        {
            return;
        }
        if (key < T->key)
        {
            Delete(T->Lc, key);
        }
        else if (key > T->key)
        {
            Delete(T->Rc, key);
        }
        else
        {
            if (T->Lc && T->Rc)
            {
                Node *tmp = T->Lc;
                while (tmp->Rc)
                {
                    tmp = tmp->Rc;
                }
                T->key = tmp->key;
                T->val = tmp->val;
                Delete(T->Lc, tmp->key);
            }
            else
            {
                Node *tmp = T;
                if (T->Lc)
                {
                    T = T->Lc;
                }
                else if (T->Rc)
                {
                    T = T->Rc;
                }
                else
                {
                    free(T);
                    T = NULL;
                }
                if (T)
                {
                    free(tmp);
                }
                return;
            }
        }
        pull(T);
        balance(T);
    }
    void Free() { FreeNode(root); }
    void FreeNode(Node *T)
    {
        if (T == NULL)
        {
            return;
        }
        if (T->Rc)
        {
            FreeNode(T->Rc);
        }
        if (T->Lc)
        {
            FreeNode(T->Lc);
        }
        free(T);
    }
};

int main()
{
    AVLTree avl;
    avl.init();
    int cmd;
    while (scanf("%d", &cmd), cmd)
    {
        // cout << "cmd: " << cmd << '\n';
        if (cmd == 1)
        {
            int k, p;
            scanf("%d %d", &k, &p);
            avl.insert(p, k);
        }
        else
        {
            avl.Find(3 - cmd);
        }
    }
    avl.Free();
}