// 混合背包 + 函数型物品优化
// 题意：有 n 种物品，每种物品有三种类型，分别是函数型物品、完全背包物品和多重背包物品。每种物品都有一个体积和一个价值，要求在总容量为 m 的情况下，求最大价值。
// 物品类型：
// 1. 函数型物品：每个物品有一个函数 f(x) = a * x^2 - b * x，表示选择 x 个该物品的价值为 f(x)，体积为 x。
// 2. 完全背包物品：每个物品有一个体积 b 和一个价值 a，表示选择任意个该物品的价值为 a * x，体积为 b * x。
// 3. 多重背包物品：每个物品有一个体积 b、一个价值 a 和一个数量 c，表示最多可以选择 c 个该物品，每个物品的体积为 b，价值为 a。
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const long long inf = -0x3f3f3f3f;

int n, m;

int main()
{
    cin >> n >> m;

    vector<long long> dp(m + 1, inf);

    dp[0] = 0;

    for(int i = 0; i < n; i ++)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            long long a, b;
            cin >> a >> b;

            vector<long long> ndp(m + 1, inf);

            for(int j = 0; j <= m; j ++)
            {
                if(dp[j] == inf) continue;

                ndp[j] = max(ndp[j], dp[j]);

                for(int x = 1; j + x <= m; x ++)
                {
                    long long val = a * x * x - b * x;

                    ndp[j + x] = max(ndp[j + x], dp[j] + val);
                }
            }

            dp.swap(ndp);
        }

        else if(t == 2)
        {
            long long a, b;
            int c;
            cin >> a >> b >> c;

            int k = 1;

            while(c > 0)
            {
                int cnt = min(k, c);

                long long val = a * cnt;
                int vol = b * cnt;

                for(int j = m; j >= vol; j --)
                {
                    if(dp[j - vol] != inf)
                    {
                        dp[j] = max(dp[j], dp[j - vol] + val);
                    }
                }

                c -= cnt;
                k *= 2;
            }
        }

        else 
        {
            long long a, b;

            cin >> a >> b;

            for(int j = b; j <= m; j ++)
            {
                if(dp[j - b] != inf)
                {
                    dp[j] = max(dp[j], dp[j - b] + a);
                }
            }
        }
    }

    long long ans = 0;

    for(auto x : dp) ans = max(ans, x);

    cout << ans;

    return 0;
}