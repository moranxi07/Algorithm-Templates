// 解释：
// 1. 离散化：将所有的坐标值进行排序去重，映射到一个连续的整数区间上。
// 2. 前缀和：利用前缀和数组快速计算区间和。对于每个添加操作，将对应位置的值累加到前缀和数组中，然后对于每个查询操作，直接通过前缀和数组计算区间和。
// 复杂度分析：
// 1. 离散化的时间复杂度为 O((n + m) log(n + m))，其中 n 是添加操作的数量，m 是查询操作的数量。
// 2. 前缀和的时间复杂度为 O(n + m)，其中 n 是添加操作的数量，m 是查询操作的数量。
// 操作：
// 1. 添加操作：将一个值添加到某个坐标上。
// 2. 查询操作：查询某个区间内的值的总和。
// 原理：
// 1. 离散化：将所有的坐标值进行排序去重，映射到一个连续的整数区间上。
// 2. 前缀和：利用前缀和数组快速计算区间和。对于每个添加操作，将对应位置的值累加到前缀和数组中，然后对于每个查询操作，直接通过前缀和数组计算区间和。
// ！！！！！find函数：用于在离散化后的数组中查找某个坐标值对应的索引位置。通过二分查找的方式，
// ！！！！！找到第一个大于等于该坐标值的位置，并返回其索引加一（因为前缀和数组是从1开始的）
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 300010;

int n, m;

vector<int> alls;

vector<pair<int, int>> add;
vector<pair<int, int>> query;

ll a[N];
ll s[N];

int find(int x)
{
    int l = 0, r = alls.size() - 1;

    while(l < r)
        {
            int mid = l + r >> 1;

            if(alls[mid] >= x) r = mid;
            else l = mid + 1;
        }

    return l + 1;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i ++)
        {
            int x, c;
            cin >> x >> c;
            add.push_back({x, c});
            alls.push_back(x);
        }
    for(int i = 0; i < m; i ++)
        {
            int l, r;
            cin >> l >> r;

            query.push_back({l, r});

            alls.push_back(l);
            alls.push_back(r);
        }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto item : add)
        {
            int x = find(item.first);
            a[x] += item.second;
        }

    for(int i = 1; i <= alls.size(); i ++)
        {
            s[i] = s[i - 1] + a[i];
        }

    for(auto item : query)
        {
            int l = find(item.first);
            int r = find(item.second);

            cout << s[r] - s[l - 1] << endl;
        }

    return 0;
}