//树换根DP
//要求一个树上所有节点到某一个节点的距离和最小，求这个节点
//换根DP的思路是先以任意一个节点为根，求出所有节点到这个根的距离和，然后再通过换根的方式
//，计算其他节点作为根时的距离和，从而找到最小的距离和对应的节点。
//公式为：long[child] = long[parent] + (n - 2 * size[child])，其中size[child]表示以child为根的子树的节点数，n表示整棵树的节点数。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int N = 50010;


vector<int> g[N];

long long dp[N];
int sz[N];

int n;


void dfs1(int u,int fa)
{
    sz[u]=1;


    for(int v:g[u])
    {
        if(v==fa)
            continue;


        dfs1(v,u);


        sz[u]+=sz[v];


        dp[u]+=dp[v]+sz[v];
    }
}



void dfs2(int u,int fa,long long &ans,int &id)
{

    if(dp[u]<ans || (dp[u]==ans && u<id))
    {
        ans=dp[u];
        id=u;
    }


    for(int v:g[u])
    {
        if(v==fa)
            continue;


        dp[v]=dp[u]+n-2*sz[v];


        dfs2(v,u,ans,id);
    }
}



int main()
{
    cin>>n;


    for(int i=1;i<n;i++)
    {
        int a,b;

        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }


    dfs1(1,0);


    long long ans=1e18;
    int id=1e9;


    dfs2(1,0,ans,id);


    cout<<id<<" "<<ans;


    return 0;
}



// 第二种；
// 解释：
// 1. 首先，我们定义了一个树的结构，其中每个节点都有一个颜色。我们需要找到一个节点，使得从该节点出发，所有与其颜色相同的节点的数量最大。
// 2. 我们使用了两次深度优先搜索（DFS）来解决这个问题。第一次DFS用于计算每个节点的初始值，第二次DFS用于在换根的过程中更新每个节点的值。
// 3. 在第一次DFS中，我们计算每个节点的初始值，即从该节点出发，所有与其颜色相同的节点的数量。我们使用了一个辅助数组samec来记录每个节点的相同颜色的邻居数量。
// 4. 在第二次DFS中，我们通过换根的方式更新每个节点的值。我们使用了一个辅助函数check来判断一个节点是否可以作为根节点，即该节点的颜色与其父节点的颜色不同。
// 5. 最后，我们遍历所有节点，找到具有最大值的节点，并输出该节点的编号和最大值的数量。

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;

int c[N];

vector<int> g[N];

int samec[N];

int dp[N];

int check(int v, int fa)
{
    int x = samec[v];
    if(fa && c[v] == c[fa]) x --;

    return x == 0;
}

void dfs1(int u, int fa)
{
    dp[1] += check(u, fa);

    for(int v : g[u])
        {
            if(v == fa) continue;

            dfs1(v, u);
        }
}

void dfs2(int u, int fa)
{
    for(int v : g[u])
        {
            if(v == fa) continue;

            int oldu;
            int oldv;
            int newu;
            int newv;

            oldu = check(u, 0);
            oldv = check(v, u);

            newu = check(u, v);
            newv = check(v, 0);

            dp[v] = dp[u] -oldu - oldv + newu + newv;

            dfs2(v, u);
        }
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin>>n;


    for(int i=1;i<=n;i++)
        cin>>c[i];


    for(int i=1;i<n;i++)
    {
        int u,v;

        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);

        if(c[u]==c[v])
        {
            samec[u]++;
            samec[v]++;
        }
    }


    dfs1(1,0);

    dfs2(1,0);


    int mx=0;
    int cnt=0;


    for(int i=1;i<=n;i++)
    {
        if(dp[i]>mx)
        {
            mx=dp[i];
            cnt=1;
        }
        else if(dp[i]==mx)
        {
            cnt++;
        }
    }


    cout<<mx<<" "<<cnt<<"\n";

    return 0;
}