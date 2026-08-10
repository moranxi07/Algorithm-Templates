// dp[u][j]: 以u为根的子树，选j个用户的最大收益
// size[u]: 以u为根的子树的用户数量
// dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - cost)
// 其中v是u的子节点，cost是u到v的边权，k是选取v子树的用户数量
// 再仔细解释一下:
// 1. 以u为根的子树，选j个用户的最大收益，分为两部分：
//    - 以u为根的子树中，选取v子树的k个用户的最大收益
//    - 以u为根的子树中，选取u的其他子树的j-k个用户的最大收益
// 2. 因为选取v子树的k个用户需要支付cost
// 3. 所以dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - cost)
// 4. 最后我们需要遍历所有的子节点v，以及所有可能的k值，来更新dp[u][j]
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 3010;
const int inf = 0x3f3f3f3f;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dp[N][N];
int sz[N];
int pay[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u)
{
    if(u > n - m)
    {
        dp[u][1] = pay[u];
        sz[u] = 1;
        return;
    }

    dp[u][0] = 0;
    sz[u] = 0;

    for(int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        int cost = w[i];

        dfs(v);

        sz[u] += sz[v];

        for(int j = sz[u]; j >= 0; j --)
        {
            for(int k = 1; k <= sz[v]; k ++)
            {
                if(j >= k)
                {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - cost);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= m; j ++)
        {
            dp[i][j] = -inf;
        }
    }

    for(int i = 1; i <= n - m; i ++)
    {
        int k;
        cin >> k;

        for(int j = 0; j < k; j ++)
        {
            int a, c;
            cin >> a >> c;
            add(i, a, c);
        }
    }

    for(int i = n - m + 1; i <= n; i ++)
    {
        cin >> pay[i];
    }

    dfs(1);

    for(int i = m; i >= 0; i --)
    {
        if(dp[1][i] >= 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}