// 不含前导零且相邻两个数字之差至少为  
// 的正整数被称为 windy 数。windy 想知道，
// 在a和b之间，包括a和b，
// 总共有多少个 windy 数？
// 1 <= a <= b <= 10^9
// 题解：
// 1. 先统计长度小于 len(b) 的 windy 数的个数
// 2. 再统计长度等于 len(b) 的 windy 数的个数
//dp[len][d] 表示长度为 len，首位数字为 d 的 windy 数的个数
// 1. 初始化长度为 1 的 windy 数的个数
// 2. 状态转移方程：
// dp[len][d] = sum(dp[len - 1][k])，其中 k 满足 abs(d - k) >= 2
// 3. 统计长度小于 len(b) 的 windy 数的个数
// 4. 统计长度等于 len(b) 的 windy 数的个数

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int N = 15;

int dp[N][10];

void init()
{
    for(int d = 0; d <= 9; d ++)
    {
        dp[1][d] = 1;
    }

    for(int len = 2; len < N; len ++)
    {
        for(int d = 0; d <= 9; d ++)
        {
            for(int k = 0; k <= 9; k ++)
            {
                if(abs(d - k) >= 2)
                {
                    dp[len][d] += dp[len - 1][k];
                }
            }
        }
    }
}

int solve(int x)
{
    if(x <= 0) return 0;

    vector<int> q;

    while(x)
    {
        q.push_back(x % 10);
        x /= 10;
    }

    int ans = 0;

    int len = q.size();

    for(int l = 1; l < len; l ++)
    {
        for(int first = 1; first <= 9; first ++)
        {
            ans += dp[l][first];
        }
    }

    int last = -100;

    for(int i = len - 1; i >= 0; i --)
    {
        int current = q[i];

        int start = (i == len - 1 ? 1 : 0);

        for(int d = start; d < current; d ++)
        {
            if(last == -100 || abs(last - d) >= 2)
            {
                ans += dp[i + 1][d];
            }
        }

        if(last != -100 && abs(last - current) < 2)
        {
            break;
        }

        last = current;

        if(i == 0) ans ++;
    }

    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;

    init();
    cout << solve(b) - solve(a - 1) << endl;

    return 0;
}