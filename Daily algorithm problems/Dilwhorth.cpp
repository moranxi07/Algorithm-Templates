// 题目木棍的连续加工  是成一条下降的链
// 一次准备要一条链
//要求最小准备  就是最小覆盖链
//Dilworth定理:最小覆盖链 = 最大不相交链 = 最大反链
//和那个二分图相似
// 最大反链也就是  二维LIS问题(可以关注一下信封嵌套问题)
// 先按长度降序排序,长度相同按宽度升序排序
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

struct Edge
{
    int l, w;
    bool operator< (const Edge &t) const
    {
        if(l == t.l)
        {
            return w > t.w;
        }

        return l > t.l;
    }
}a[N];

int dp[N];

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i].l >> a[i].w;
    }

    sort(a, a + n);

    int ans = 0;

    for(int i = 0; i < n; i ++)
    {
        dp[i] = 1;

        for(int j = 0; j < i; j ++)
        {
            if(a[j].w < a[i].w)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}