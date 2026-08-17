// 树的同构
// 用st来找root，st[i]表示i是否是子节点，如果不是子节点就是根节点
// u是t1的根节点，v是t2的根节点
// 如果节点字母相同，就尝试两种匹配：
// 1. t1的左子树和t2的左子树匹配，t1的右子树和t2的右子树匹配
// 2. t1的左子树和t2的右子树匹配，t1的右子树和t2的左子树匹配
#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

struct Node
{
    char val;
    int l, r;
}t1[N], t2[N];

int n1, n2;
bool st1[N], st2[N];

int build(Node t[], bool st[], int n)
{
    for(int i = 0; i < n; i ++)
        {
            char x, l, r;
            cin >> x >> l >> r;
            t[i].val = x;
            if(l == '-') t[i].l = -1;
            else 
            {
                t[i].l = l - '0';
                st[t[i].l] = true;
            }

            if(r == '-') t[i].r = -1;

            else
            {
                t[i].r = r - '0';
                st[t[i].r] = true;
            }
        }

    for(int i = 0; i < n; i ++)
        {
            if(!st[i])
                return i;
        }

    return -1;
}

bool check(int u, int v)
{
    if(u == -1 && v == -1) return true;
    if(u == -1 || v == -1) return false;
    if(t1[u].val != t2[v].val) return false;

    bool a = check(t1[u].l, t2[v].l) && check(t1[u].r, t2[v].r);
    bool b = check(t1[u].l, t2[v].r) && check(t1[u].r, t2[v].l);

    return a || b;
}

int main()
{
    cin >> n1;

    int root1 = build(t1, st1, n1);

    cin >> n2;

    int root2 = build(t2, st2, n2);

    if(check(root1, root2)) cout << "Yes" << endl;
    else cout << "No";

    return 0;
}