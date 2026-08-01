//dp[][0] 以 𝑢为根的子树中，节点 𝑢不放士兵时，覆盖所有子树内部边所需的最少士兵数。
//dp[][1] 以 𝑢为根的子树中，节点 𝑢放士兵时，覆盖所有子树内部边所需的最少士兵数。
//状态转移方程：
//dp[u][0] = sum(dp[v][1])，其中 v 为 u 的所有子节点。
//dp[u][1] = sum(min(dp[v][0], dp[v][1]))
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1510, M = N * 2;

int n;
int dp[N][2];
int e[M], ne[M], h[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u, int fa)
{
    dp[u][0] = 0;
    dp[u][1] = 1;

    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];

        if(j == fa) continue;

        dfs(j, u);

        dp[u][0] += dp[u][1];
        dp[u][1] += min(dp[j][1], dp[j][0]);
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        int u, k;
        while(k --)
        {
            int v;
            cin >> v;
            add(u, v);
            add(v, u);
        }
    }

    dfs(0, -1);

    cout << min(dp[0][0], dp[0][1]);

    return 0;
}