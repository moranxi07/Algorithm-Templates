  #include <iostream>
  #include <cstring>
  #include <algorithm>
  #include <cstdio>
  #include <vector>
  #include <queue>
  #include <unordered_map>

  using namespace std;

  const int N = 100010;      // 改成题目 n 的上界（原 100 太小）
  const int inf = 1e9;

  int n, m;
  long long C;
  int d[N];
  vector<vector<int>> g;     // 关键：先不定大小，读入 n 后再 assign

  void bfs()
  {
      for (int i = 1; i <= n; i++) d[i] = inf;   // 关键：BFS 前初始化距离

      queue<int> q;
      d[1] = 0;
      q.push(1);

      while (!q.empty())
      {
          auto t = q.front();
          q.pop();

          for (int v : g[t])
          {
              if (d[v] == inf)
              {
                  d[v] = d[t] + 1;
                  q.push(v);
              }
          }
      }
  }

  int main()
  {
      cin >> n >> m >> C;

      g.assign(n + 1, {});   // 关键：读入 n 后再定邻接表大小

      vector<long long> cost(n + 1);
      for (int i = 1; i <= n; i++) cin >> cost[i];

      for (int i = 0; i < m; i++)
      {
          int a, b;
          cin >> a >> b;
          g[a].push_back(b);
      }

      bfs();

      if (d[n] == inf)
      {
          cout << 0 << endl;
          return 0;
      }

      int dist = d[n];
      vector<vector<int>> level(dist + 1);
      for (int i = 1; i <= n; i++)
      {
          if (d[i] <= dist)
          {
              level[d[i]].push_back(i);
          }
      }

      vector<unordered_map<long long, long long>> dp(n + 1);   // 关键：n+1，不是 dist+1

      if (cost[1] <= C) dp[1][cost[1]] = 1;
      for (int d1 = 0; d1 <= dist; d1++)
      {
          for (int u : level[d1])
          {
              if (dp[u].empty()) continue;
              for (auto &v : dp[u])
              {
                  long long cc = v.first;
                  long long cnt = v.second;

                  for (int ne : g[u])
                  {
                      if (d[ne] == d1 + 1)
                      {
                          long long new_cost = cc + cost[ne];
                          if (new_cost <= C)
                          {
                              dp[ne][new_cost] += cnt;
                          }
                      }
                  }
              }
          }
      }

      long long ans = 0;
      for (auto &v : dp[n])
      {
          ans += v.second;
      }

      cout << ans << endl;
      return 0;
  }