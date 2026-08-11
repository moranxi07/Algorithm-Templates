// 解释一下思想:
// 1. 先用 Kruskal 算法构造出一棵最小生成树, 并且在构造的过程中, 将每条边的权值存储在一个数组中, 以便后续查询.
// 2. 然后对这棵树进行 DFS 遍历, 计算每个节点的深度和父节点, 并且使用倍增法预处理每个节点的祖先节点.
// 3. 最后对于每个查询, 先判断两个节点是否在同一棵树中, 如果不在同一棵树中, 输出 -1. 否则, 使用倍增法求出两个节点的最近公共祖先, 并输出该祖先节点对应的边权值.
// 将边换成对应点并且带有权值;
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 20010, M = 50010;

struct Edge
{
    int a, b, w;
    bool operator< (const Edge& t)const
    {
        return w > t.w;
    }
}e[M];

int n, m, q;
int p[N];
int fa[N][20];
int d[N];
int val[N];
vector<int> tree[N];
int tot;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void dfs(int u, int father)
{
    d[u] = d[father] + 1;
    fa[u][0] = father;

    for(int i = 1; i < 20; i ++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for(int v : tree[u])
    {
        if(v == father) continue;
        dfs(v, u);
    }
}

int lca(int x, int y)
{
    if(d[x] < d[y]) swap(x, y);

    for(int i = 19; i >= 0; i --)
    {
        if(d[fa[x][i]] >= d[y])
        {
            x = fa[x][i];
        }
    }

    if(x == y) return x;

    for(int i = 19; i >= 0; i --)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; i ++)
    {
        cin >> e[i].a >> e[i].b >> e[i].w;
    }

    sort(e, e + m);

    for(int i = 1; i <= n; i ++) p[i] = i;

    tot = n;

    for(int i = 0; i < m; i ++)
    {
        int a = find(e[i].a);
        int b = find(e[i].b);
        int w = e[i].w;

        if(a != b)
        {
            tot ++;
            val[tot] = w;
            p[a] = p[b] = tot;
            p[tot] = tot;
            tree[tot].push_back(a);
            tree[tot].push_back(b);
            tree[a].push_back(tot);
            tree[b].push_back(tot);
        }
    }

    for(int i = 1; i <= tot; i ++)
    {
        if(p[i] == i) dfs(i, 0);
    }

    cin >> q;

    while(q --)
    {
        int x, y;
        cin >> x >> y;

        if(find(x) != find(y))
        {
            cout << -1 << endl;
        }

        else
        {
            int l = lca(x, y);
            cout << val[l] << endl;
        }
    }

    return 0;
}