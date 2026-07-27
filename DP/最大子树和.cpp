//每个节点都有值
//删减枝干
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 16010, M = 32010;

int e[M], ne[M], idx, h[N];
int n;
bool st[N];
int a[N];
int dp[N];
int ans = -0x3f3f3f3f;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u, int fa)
{
    dp[u] = a[u];
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];

        if(j == fa) continue;

        dfs(j, u);

        dp[u] += max(0, dp[j]);
    }

    ans = max(ans, dp[u]);
}

int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n - 1; i ++)
    {
        int a, b;
        cin >> a >> b;
        add(a ,b);
        add(b, a);
    }

    dfs(1, 0);

    cout << ans << endl;

    return 0;
}