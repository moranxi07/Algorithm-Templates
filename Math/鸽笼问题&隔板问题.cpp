#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
int main()
{
	int t;
	cin >> t;
	
	while(t --)
	{
		cin >> n;
		
		vector<int> cnt(1001, 0);
		
		long long s = 0;
		
		for(int i = 1; i <= n; i ++)
		{
			int x;
			cin >> x;
			s += x;
			cnt[x] ++;
		}
		
		int m = 0;
		int v = 0;
		
		for(int i = 1; i <= 1000; i ++)
		{
			if(cnt[i] > m)
			{
				m = cnt[i];
				v = i;
			}
		}
		
		if(m <= (n + 1) / 2) // n - m <= m - 1; // 让m当隔板 
		{
			cout << s << endl;
		}
		
		
		else  // 让剩下的 n - m 个当隔板; 
		{
			cout << s - (2 * m - n - 2) * v << endl;
 		}
	}
	
	return 0;
}