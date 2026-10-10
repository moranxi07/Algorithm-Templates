#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010, M = N * 2;
const int inf = 1e8;

int e[M], ne[M], idx, h[N], f[N];
int cur[N], d[N];
int n, m, S, T;

void add(int a, int b, int c)
{
    e[idx] = b;
    f[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;

    e[idx] = a;
    f[idx] = 0;
    ne[idx] = h[b];
    h[b] = idx ++;
}

bool bfs()
{
    memset(d, -1, sizeof d);

    queue<int> q;
    q.push(S);
    d[S] = 0;
    cur[S] = h[S];

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();

        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];

            if(f[i] && d[j] == -1)
            {
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if(j == T) return true;
                q.push(j);
            }
        }
    }

    return false;
}

int find(int u, int limit)
{
    if(u == T) return limit;
    int flow = 0;

    for(int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        int j = e[i];
        cur[u] = i;

        if(f[i] && d[j] == d[u] + 1)
        {
            int t = find(j, min(f[i], limit - flow));
            if(!t) d[j] = -1;

            f[i] -= t;
            f[i ^ 1] += t;
            flow += t;
        }
    }

    return flow;
}

int dinic()
{
    int r = 0;
    int flow;

    while(bfs()) while(flow = find(S, inf)) r += flow;
    return r;
}