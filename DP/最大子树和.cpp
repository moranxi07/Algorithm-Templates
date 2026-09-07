// 题目：
// 给定一棵 n 个节点的树，每个节点都有一个权值，求树中最大子树和。
// 输入格式：
// 第一行输入一个整数 n，表示树的节点数。
// 第二行输入 n 个整数，表示每个节点的权值。
// 接下来 n-1 行，每行输入两个整数 a, b，表示节点 a 和节点 b 之间有一条边。
// 输出格式：
// 输出一个整数，表示树中最大子树和。
//每个节点都有值
//删减枝干
// dp[j] 表示以 j 为根的子树的最大子树和
// 状态转移方程：dp[u] = a[u] + sum(max(0, dp[j]));
// 解释：
// 1. 初始化 dp[u] 为节点 u 的权值 a[u]。
// 2. 遍历节点 u 的所有子节点 j，递归计算 dp[j]。
// 3. 对于每个子节点 j，如果 dp[j] 大于 0，则将其加入 dp[u]，否则不加入。
// 4. 最终 dp[u] 就是以节点 u 为根的子树的最大子树和。

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