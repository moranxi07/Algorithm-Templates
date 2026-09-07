// 题意：
// 有n个点，点的坐标为(x,y)，要求在y轴上放置最少数量的雷达，使得每个点都能被雷达覆盖。
// 雷达的覆盖范围是一个半径为d的圆，雷达只能放在y=0的直线上。
// 输入：n d
// 输出：最少雷达数量;
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<pair<double, double>> seg;

    for(int i = 0; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        if(y > d)
        {
            cout << -1 << endl;
            return 0;
        }

        double dx = sqrt(1.0 * d * d - 1.0 * y * y);
        seg.push_back({x - dx, x + dx});
    }

    sort(seg.begin(), seg.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    int ans = 0;
    double last = -1e18;
    for(auto &p : seg)
    {
        if(p.first > last)
        {
            ans ++;
            last = p.second;
        }
    }

    cout << ans << endl;

    return 0;
}