// 解释一下:
// 1. 将原来的 n*n 的矩阵旋转 45 度, 变成一个 2n*2n 的矩阵
// 2. 预处理前缀和, 方便快速求出任意矩形的和
// 3. 对于每个点, 求出以该点为中心, 半径为 k 的菱形的和
// 4. 取所有菱形和的最大值
// 曼哈顿到离转变为切比雪夫距离的关键是旋转 45 度, 这样原来的菱形就变成了一个正方形, 可以用前缀和快速求出正方形的和
// 复杂度分析:
// 1. 旋转 45 度的复杂度是 O(n^2)
// 2. 预处理前缀和的复杂度是 O(n^2)
// 3. 对于每个点求出以该点为中心, 半径为 k 的菱形的和的复杂度是 O(n^2)
// 4. 总的复杂度是 O(n^2)
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 810;

int n, k;
long long b[N][N];
long long s[N][N];

long long get(int x1, int y1, int x2, int y2)
{
    return s[x2][y2]
         - s[x1 - 1][y2]
         - s[x2][y1 - 1]
         + s[x1 - 1][y1 - 1];
}

int main()
{
    cin >> n >> k;

    int m = 2 * n;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            int x;
            cin >> x;

            int u = i + j;
            int v = i - j + n;

            b[u][v] = x;
        }
    }

    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            s[i][j] = s[i - 1][j]
                    + s[i][j - 1]
                    - s[i - 1][j - 1]
                    + b[i][j];
        }
    }

    long long ans = 0;


    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            int u = i + j;
            int v = i - j + n;

            int x1 = max(1, u - k);
            int y1 = max(1, v - k);

            int x2 = min(m, u + k);
            int y2 = min(m, v + k);

            ans = max(ans, get(x1, y1, x2, y2));
        }
    }

    cout << ans << endl;

    return 0;
}