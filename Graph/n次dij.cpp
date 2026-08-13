// 题目：服务器感兴趣问题
// 描述：有n个服务器，编号为1~n，每个服务器有一个等级r[i]，有m条双向边，每条边有一个权值t。对于每个服务器s，定义一个服务器v对s感兴趣，当且仅当从v到s的最短路径长度小于v到最近的等级大于r[s]的服务器的最短路径长度。求所有服务器对所有服务器感兴趣的总数。
// 输入：第一行两个整数n和m，表示服务器的数量和边的数量。第二行n个整数r[i]，表示每个服务器的等级。接下来m行，每行三个整数a、b、t，表示服务器a和服务器b之间有一条权值为t的双向边。
// 输出：一行一个整数，表示所有服务器对所有服务器感兴趣的总数
// 为什么这样想？
// 1. 先预处理出每个服务器v到最近的等级大于k的服务器的最短路径长度high[k][v]，其中k为服务器s的等级r[s]。
// 2. 然后对于每个服务器s，使用单源Dijkstra算法从s出发，计算每个服务器v到s的最短路径长度d[v]，并统计满足d[v] < high[r[s]][v]的服务器v的数量，即为对s感兴趣的服务器数量。    
// 3. 最后将所有服务器对所有服务器感兴趣的数量累加即可得到答案。
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> PII;

const int N = 30010;
const int M = 300010;
const ll INF = 1e18;

int n, m;

int h[N], e[M], w[M], ne[M], idx;

int r[N];

// high[k][v]
// v 到最近的 rank > k 的服务器的距离
ll high[11][N];

// 每次单源剪枝 Dijkstra 使用
ll dista[N];
int tag[N];
int timestamp;


void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}


// 多源 Dijkstra
void dijkstra_high(int k)
{
    priority_queue<PII, vector<PII>, greater<PII>> q;

    for(int i = 1; i <= n; i++)
    {
        high[k][i] = INF;

        if(r[i] > k)
        {
            high[k][i] = 0;

            q.push({0, i});
        }
    }


    while(q.size())
    {
        auto t = q.top();
        q.pop();

        ll d = t.first;
        int u = t.second;

        if(d != high[k][u])
            continue;


        for(int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];

            if(high[k][v] > d + w[i])
            {
                high[k][v] = d + w[i];

                q.push({high[k][v], v});
            }
        }
    }
}


// 从服务器 s 出发
// 统计多少个 v 对 s 感兴趣
ll dijkstra(int s)
{
    int k = r[s];

    priority_queue<PII, vector<PII>, greater<PII>> q;

    timestamp++;

    tag[s] = timestamp;
    dista[s] = 0;

    q.push({0, s});

    ll res = 0;


    while(q.size())
    {
        auto t = q.top();
        q.pop();

        ll d = t.first;
        int u = t.second;

        if(tag[u] != timestamp || d != dista[u])
            continue;


        // 不满足感兴趣条件
        // 并且从这里继续扩展也没有意义
        if(d >= high[k][u])
            continue;


        // u 对 s 感兴趣
        res++;


        for(int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];

            ll nd = d + w[i];


            if(tag[v] != timestamp)
            {
                tag[v] = timestamp;
                dista[v] = INF;
            }


            if(dista[v] > nd)
            {
                dista[v] = nd;

                q.push({nd, v});
            }
        }
    }


    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }


    memset(h, -1, sizeof h);


    for(int i = 1; i <= m; i++)
    {
        int a, b, t;

        cin >> a >> b >> t;

        add(a, b, t);
        add(b, a, t);
    }


    // 预处理：
    // high[k][v] = v 到最近 rank > k 点的距离
    for(int k = 1; k <= 10; k++)
    {
        dijkstra_high(k);
    }


    ll ans = 0;


    // 对每个服务器 w：
    // 求有多少 v 对 w 感兴趣
    for(int i = 1; i <= n; i++)
    {
        ans += dijkstra(i);
    }


    cout << ans << '\n';

    return 0;
}