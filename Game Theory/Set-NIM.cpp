//只能在规定集合中取
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int s[N], f[M];

int sg(int x)
{
    if(f[x] != -1) return f[x];
    
    unordered_set<int> have;
    
    for(int i = 1; i <= m; i ++)
    {
        int sum = s[i];
        if(x >= sum) have.insert(sg(x - sum));
    }
    
    for(int i = 0; ; i ++)
    {
        if(!have.count(i))
        {
            return f[x] = i;
        }
    }
}
int main()
{
    cin >> m;
    
    for(int i = 1; i <= m; i ++) cin >> s[i];
    
    cin >> n;
    memset(f, -1, sizeof f);
    
    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    
    if(res) cout << "Yes";
    else cout << "No";
    
    return 0;
}