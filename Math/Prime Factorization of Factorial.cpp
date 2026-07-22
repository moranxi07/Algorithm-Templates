#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] * i <= n; j ++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
 
int main()
{
    int n;
    cin >> n;
    get(n);
    
    for(int i = 0; i < cnt; i ++)
    {
        int p = primes[i];
        int s = 0;
        for(int j = n; j > 0; j /= p) // 这是 Legendre公式（勒让德公式）。
                                        // p的次数在n！中
                                        // j / p + j / p^2 ... 
        {
            s += j / p;
        }
        
        cout << p << ' ' << s << endl;;
    }
    
    return 0;
}