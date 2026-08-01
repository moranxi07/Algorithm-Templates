// 卡特兰数 DP  (catalan)
//dp[i] = dp[j] * dp[i - 1 - j]  (j从0到i - 1求和);
//dp[0] = 1！！！！！
//dp[i]表示i个节点的二叉树的个数
//卡特兰数公式：C(n) = (2n)! / ((n + 1)! * n!) = C(2n, n) / (n + 1)
//卡特兰数的应用：
//1. 二叉树的个数
//2. 括号匹配的个数
//3. 栈的出栈序列个数
//4. 凸多边形的三角剖分个数
//5. 由n个点组成的非交叉连线的个数
//这里是
//关于圆的有趣的问题：在圆上有 个不同的点，
//小 x 想用  条线段把这些点连接起来（每个点只能连一条线段），
//使所有的线段都不相交，他想知道这样的连接方案有多少种？

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e8 + 7;
const int N = 3010;

long long dp[N];
int n;

int main()
{
    cin >> n;

    dp[0] = 1;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j < i; j ++)
        {
            dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % mod;
        }
    }

    cout << dp[n];

    return 0;
}