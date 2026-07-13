#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 5010;

int a[N];
int f[N];          // 最长下降子序列长度
long long g[N];    // 对应方案数

int n;

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];


    int ans = 0;


    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        g[i] = 1;


        set<int> used;  // 当前状态i中，已经使用过的前驱价格


        for(int j = i - 1; j >= 1; j--)
        {
            if(a[j] > a[i])   // 严格下降
            {
                if(f[j] + 1 > f[i])
                {
                    // 找到更长方案
                    f[i] = f[j] + 1;
                    g[i] = g[j];

                    // 新长度，需要重新统计前驱价格
                    used.clear();
                    used.insert(a[j]);
                }
                else if(f[j] + 1 == f[i])
                {
                    // 同长度方案，去掉重复价格序列
                    if(!used.count(a[j]))
                    {
                        g[i] += g[j];
                        used.insert(a[j]);
                    }
                }
            }
        }

        ans = max(ans, f[i]);
    }


    long long res = 0;

    set<int> used;  // 最终统计时去重


    for(int i = 1; i <= n; i++)
    {
        if(f[i] == ans)
        {
            if(!used.count(a[i]))
            {
                res += g[i];
                used.insert(a[i]);
            }
        }
    }


    cout << ans << " " << res << endl;


    return 0;
}
