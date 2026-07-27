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