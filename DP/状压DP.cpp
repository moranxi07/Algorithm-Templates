// 状态压缩DP模板
// 题目：旅行商问题
// 描述：给定n个城市和城市之间的距离，求一条最短路径，使得旅行商从起点出发，经过每个城市恰好一次后返回起点。
// 输入：第一行一个整数n，表示城市的数量。接下来n行，每行n个整数，表示城市之间的距离矩阵s[i][j]。
// 输出：一行一个整数，表示最短路径的长度。
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 25;

int s[N][N];
int dp[1 << 20][20];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            cin >> s[i][j];
        }
    }

    memset(dp, 0x3f ,sizeof dp);
    dp[1][0] = 0;

    for(int mask = 1; mask < (1 << n); mask ++)
    {
        // mask表示当前已经访问过的点集，i表示当前访问的最后一个点
        for(int i = 0; i < n; i ++)
        {
            if(!(mask & (1 << i))) continue;
            if(dp[mask][i] == inf) continue;
            
            // 遍历所有未访问的点，更新状态转移方程
            for(int j = 0; j < n; j ++)
            {
                if(mask & (1 << j)) continue;

                dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + s[i][j]);
            }
        }
    }

    int res = inf;
    int k = (1 << n) - 1;
    for(int i = 0; i < n; i ++)
    {
        res = min(res, dp[k][i] + s[i][0]);
    }

    cout << res;

    return 0;
}