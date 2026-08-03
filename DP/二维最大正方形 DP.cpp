// dp[i][j] 表示以 (i, j) 为右下角的最大正方形的边长
// 如果 (i, j) 是树，则 dp[i][j] = 0
// 否则 dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
// 最终答案为所有 dp[i][j] 的最大值
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, t;
bool tree[N][N];
int dp[N][N];

int main()
{
    cin >> n >> t;

    for(int i = 1; i <= t; i ++)
    {
        int x, y;
        cin >> x >> y;
        tree[x][y] = true;
    }

    int ans = 0;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(tree[i][j]) dp[i][j] = 0;

            else
            {
                dp[i][j] = min({
                    dp[i - 1][j],
                    dp[i - 1][j - 1],
                    dp[i][j - 1]
                }) + 1;

                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}