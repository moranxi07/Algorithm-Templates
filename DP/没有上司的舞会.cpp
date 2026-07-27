//尽量不让子节点和父节点同时选中，选中父节点则子节点不能选中，选中子节点则父节点不能选中
//没有上司的舞会
//https://www.acwing.com/problem/content/description/1003/
//f[u][0]表示不选中u节点的最大快乐值，f[u][1]表示选中u节点的最大快乐值
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010;

int n;
int happy[N];
int h[N], e[N], ne[N], idx;
int f[N][2];
bool has[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u)
{
    f[u][1] = happy[u];

    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];

        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    cin >> n;

    memset(h, -1, sizeof h);

    for(int i = 1; i <= n; i ++)
    {
        cin >> happy[i];
    }

    for(int i = 1; i <= n - 1; i ++)
    {
        int a, b;
        cin >> a >> b;
        has[a] = true;
        add(b, a);
    }

    int root = 1;
    while(has[root]) root ++;

    dfs(root);

    cout << max(f[root][0], f[root][1]);

    return 0;
}