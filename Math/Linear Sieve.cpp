#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

//线性筛原理: n只会被最小质因子筛掉；

// i % pj == 0
//   pj 一定是i的最小质因子  因为从小到大枚举
//   那么pj一定是pj * i的最小质因子；

// i % pj != 0
//   pj小于i的所有质因子  则pj一定也是pj * i的最小质因子；
void get_primes(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;
        
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i] = true; // 综上  所以这里一定会被筛
            if(i % primes[j] == 0) break;// 第一次 则为最小质因子
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    get_primes(n);
    
    cout << cnt;
    
    return 0;
}