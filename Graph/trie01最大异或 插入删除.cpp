/*
D. Vasiliy's Multiset
time limit per test4 seconds
memory limit per test256 megabytes
Author has gone out of the stories about Vasiliy, so here is just a formal task description.

You are given q queries and a multiset A, initially containing only integer 0. There are three types of queries:

"+ x" — add integer x to multiset A.
"- x" — erase one occurrence of integer x from multiset A. It's guaranteed that at least one x is present in the multiset A before this query.
"? x" — you are given integer x and need to compute the value , i.e. the maximum value of bitwise exclusive OR (also know as XOR) of integer x and some integer y from the multiset A.
Multiset is a set, where equal elements are allowed.

Input
The first line of the input contains a single integer q (1 ≤ q ≤ 200 000) — the number of queries Vasiliy has to perform.

Each of the following q lines of the input contains one of three characters '+', '-' or '?' and an integer xi (1 ≤ xi ≤ 109). It's guaranteed that there is at least one query of the third type.

Note, that the integer 0 will always be present in the set A.

Output
For each query of the type '?' print one integer — the maximum value of bitwise exclusive OR (XOR) of integer xi and some integer from the multiset A.

Example
InputCopy
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11
OutputCopy
11
10
14
13
Note
After first five operations multiset A contains integers 0, 8, 9, 11, 6 and 1.

The answer for the sixth query is integer  — maximum among integers , , ,  and .


*/
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