#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200000 * 31 + 10;

struct Node
{
	int son[2];
	int cnt;
}trie[N];

int tot = 0;

void modify(int x, int del)
{
	int u = 0;
	for(int i = 30; i >= 0; i --)
	{
		int bit = (x >> i) & 1;
		
		if(!trie[u].son[bit])
		{
			trie[u].son[bit] = ++ tot;
		}
		
		u = trie[u].son[bit];
		
		trie[u].cnt += del;
	}
}

int query(int x)
{
	int u = 0;
	int ans = 0;
	
	for(int i = 30; i >= 0; i --)
	{
		int bit = (x >> i) & 1;
		int want = bit ^ 1;
		
		int v = trie[u].son[want];
		
		if(trie[v].cnt > 0 && v)
		{
			ans |= (1 << i);
			u = v;
		}
		
		else
		{
			u = trie[u].son[bit];
		}
	}
	
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    modify(0, 1);

    while(q--)
    {
        char op;
        int x;

        cin >> op >> x;

        if(op == '+')
        {
            modify(x, 1);
        }
        else if(op == '-')
        {
            modify(x, -1);
        }
        else
        {
            cout << query(x) << '\n';
        }
    }

    return 0;
}