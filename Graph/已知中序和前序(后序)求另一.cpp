/*// 前序：根 左 右
visit(u);
dfs(left);
dfs(right);

// 中序：左 根 右
dfs(left);
visit(u);
dfs(right);

// 后序：左 右 根
dfs(left);
dfs(right);
visit(u);*/

//知道前序和中序求后序
//前序：根 左 右
#include <iostream>

using namespace std;

const int N = 35;

int n;
int pre[N], in[N];

bool first = true;

void dfs(int pl, int pr, int il, int ir)
{
    if(pl > pr) return;

    int root = pre[pl];

    int k = il;
    while(in[k] != root) k++;

    int lsize = k - il;

    // 左子树
    dfs(
        pl + 1,
        pl + lsize,
        il,
        k - 1
    );

    // 右子树
    dfs(
        pl + lsize + 1,
        pr,
        k + 1,
        ir
    );

    // 后序：左 右 根
    if(!first) cout << ' ';
    cout << root;
    first = false;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> pre[i];

    for(int i = 0; i < n; i++)
        cin >> in[i];

    dfs(0, n - 1, 0, n - 1);

    cout << endl;

    return 0;
}

//知道中序和后序求前序

#include <iostream>

using namespace std;

const int N = 35;

int n;
int post[N], in[N];
int lson[10010], rson[10010];

int build(int il, int ir, int pl, int pr)
{
    if(il > ir) return 0;

    int root = post[pr];

    int k = il;
    while(in[k] != root) k++;

    int lsize = k - il;

    lson[root] = build(
        il, k - 1,
        pl, pl + lsize - 1
    );

    rson[root] = build(
        k + 1, ir,
        pl + lsize, pr - 1
    );

    return root;
}

bool first = true;

void preorder(int u)
{
    if(!u) return;

    if(!first) cout << ' ';
    cout << u;
    first = false;

    preorder(lson[u]);
    preorder(rson[u]);
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> post[i];

    for(int i = 0; i < n; i++)
        cin >> in[i];

    int root = build(0, n - 1, 0, n - 1);

    preorder(root);

    cout << endl;

    return 0;
}

// 层序遍历
#include <iostream>
#include <queue>

using namespace std;

const int N = 35;

int n;
int post[N], in[N];

int lson[10010], rson[10010];

int build(int il, int ir, int pl, int pr)
{
    if(il > ir)
        return 0;

    int root = post[pr];

    int k = il;

    while(in[k] != root)
        k++;

    int lsize = k - il;

    lson[root] = build(
        il, k - 1,
        pl, pl + lsize - 1
    );

    rson[root] = build(
        k + 1, ir,
        pl + lsize, pr - 1
    );

    return root;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> post[i];

    for(int i = 0; i < n; i++)
        cin >> in[i];

    int root = build(0, n - 1, 0, n - 1);

    queue<int> q;

    q.push(root);

    bool first = true;

    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        if(!first)
            cout << ' ';

        cout << t;

        first = false;

        if(lson[t])
            q.push(lson[t]);

        if(rson[t])
            q.push(rson[t]);
    }

    cout << endl;

    return 0;
}