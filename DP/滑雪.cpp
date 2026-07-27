//二维数组最长下降序列
//记忆化搜索+DP
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 110;

int r, c;
int h[N][N];
int dp[N][N];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;

    for(int k = 0; k < 4; k ++)
    {
        int a = x + dx[k];
        int b = y + dy[k];

        if(a < 1 || a > r || b < 1 || b > c)
        {
            continue;
        }

        if(h[a][b] < h[x][y])
        {
            dp[x][y] = max(dp[x][y], dfs(a, b) + 1);
        }
    }

    return dp[x][y];
}

int main()
{
    cin >> r >> c;

    for(int i = 1; i <= r; i ++)
    {
        for(int j = 1; j <= c; j ++)
        {
            cin >> h[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= r; i ++)
    {
        for(int j = 1; j <= c; j ++)
        {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans << endl;

    return 0;
}