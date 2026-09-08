#include <bits/stdc++.h>
  using namespace std;
  typedef long long ll;

  const int N = 500010;

  struct Node {
      int son[26];
      int cnt;
      Node() { memset(son, 0, sizeof son); cnt = 0; }
  };

  Node trie[N];
  int tot = 1;
  int reach[N];          // reach[k] = f_{i,k}：count >= k 的最大深度

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      int n;
      cin >> n;

      ll total = 0;

      for (int i = 1; i <= n; i++) 
	  {
          string s;
          cin >> s;

          int u = 1; // 根节点赋值为1； 
          for (int d = 1; d <= (int)s.size(); d++) 
		  {
		  	int c = s[d - 1] - 'a';
		  	if(!trie[u].son[c])  trie[u].son[c] = ++ tot;// 如果当前u字符 之前并没有连接字符c那么重新赋值并且连接; 
		  	u = trie[u].son[c]; // 让u等于当前c的位置 
		  	trie[u].cnt ++; // 看看当前c以前算上这一次一共有几个字符串来过； 
		  	
		  	int k = trie[u].cnt;  //准备更新 选k个字符串时的大小； 
		  	
		  	if(k < i)  
		  	{
		  		if(d > reach[k])  //reach[k] 从前i个选k个公共最长大小; 
		  		{
		  			total -= (ll)(reach[k] ^ k);// 减去原来的； 
		  			total += (ll)(d ^ k); // 加上现在的； 
		  			reach[k] = d;
				  }
			}
			
			else // k == i； //（如果每个都有这个字符串） 
			{
				if(d > reach[k]) reach[k] = d;  //就是 每个字符串前d个都一样了； 
			}
		  }
		  
		  total += (ll)(reach[i] ^ i); // 之前未加入i字符串之前没有reach[i]  现在必须要每次加入都更新新的； 
		  cout << total << endl;
      }

      return 0;
  }