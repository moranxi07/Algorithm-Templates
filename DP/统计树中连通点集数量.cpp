// 统计树中连通点集数量
// 给定一棵树，求树中连通点集的数量。
// dp[u]表示以u为根的子树中连通点集的数量。
// 状态转移方程：dp[u] = ∏(dp[v] + 1)，其中v为u的子节点。
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 100010;
const ll mod = 1e9 + 7;

int n;
vector<int> g[N];
int fa[N];
ll dp[N];

int main()
{
    cin >> n;

    for(int i = 1; i < n; i ++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> order;
    order.reserve(n);

    fa[1] = 0;
    order.push_back(1);

    for(int i = 0; i < n; i ++)
    {
        int a = order[i];

        for(int b : g[a])
        {
            if(b == fa[a]) continue;

            fa[b] = a;
            order.push_back(b);
        }
    }

    ll ans = 0;

    for(int i = n - 1; i >= 0; i --)
    {
        int u = order[i];
        dp[u] = 1;

        for(int v : g[u])
        {
            if(fa[v] == u)
            {
                dp[u] = dp[u] * (dp[v] + 1) % mod;
            }
        }

        ans = (ans + dp[u]) % mod;
    }

    cout << ans << endl;

    return 0;
}