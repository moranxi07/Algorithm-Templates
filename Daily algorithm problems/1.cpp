// 本题主要思路为 首先将所有目标覆盖点用
//某一圆心取半径全部覆盖
//接下来枚举目标覆盖点到另一圆心的半径
//从小到大排序
//逐渐的将小半径的覆盖点转移到另一圆中
// 枚举计算半径的最小值

//其中suffix数组的作用是记录从当前位置到最后一个点的最大半径；
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10010;

struct Node
{
    int a, b;
    bool operator< (const Node &t) const
    {
        return a < t.a;
    }
};

int main()
{
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int n;
    cin >> n;

    vector<Node> v(n);

    for(int i = 0; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;

        int da = (x - x1) * (x - x1) + (y - y1) * (y- y1);
        int db = (x - x2) * (x - x2) + (y - y2) * (y- y2);

        v[i] = {da, db};
    }

    sort(v.begin(), v.end());

    int ans = 1e9;

    int maxb = 0;
    for(auto x : v)
    {
        maxb = max(maxb, x.b);
    }

    ans = maxb;

    int maxbremain = 0;

    vector<int> suffix(n + 1);

    for(int i = n - 1; i >= 0; i --)
    {
        suffix[i] = max(suffix[i + 1], v[i].b);
    }

    for(int i = 0; i < n; i ++)
    {
        int ra = v[i].a;

        int rb = suffix[i + 1];

        ans = min(ans, ra + rb);
    }

    cout << ans;

    return 0;
}