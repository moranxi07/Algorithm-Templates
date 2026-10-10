#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n;
int w[N];
int banMask[N];

int dp[1 << N];

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> w[i];

    int m;
    cin >> m;

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        banMask[a] |= 1 << b;
        banMask[b] |= 1 << a;
    }

    int S = 1 << n;

    for(int mask = 1; mask < S; mask++)
    {
        int i = __builtin_ctz(mask); // 统计mask末尾有几个连续的0(也就是第一个1的位置)

        // 不选 i
        int mask1 = mask & ~(1 << i);

        // 选 i，同时删除所有与 i 冲突的人
        int mask2 = mask1 & ~banMask[i];

        dp[mask] = max(
            dp[mask1],
            w[i] + dp[mask2]
        );
    }

    cout << dp[S - 1] << '\n';

    return 0;
}