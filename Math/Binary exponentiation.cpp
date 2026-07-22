/*
pow(a, n) = 1, 当 n = 0
pow(a, n) = pow(a, n/2) * pow(a, n/2), 当 n 为偶数
pow(a, n) = a * pow(a, n-1), 当 n 为奇数
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;


int qki(int a, int k, int p)
{
    int res = 1;
    
    while(k > 0)
    {
        if(k & 1) res = (ll) res * a % p;
        k >>= 1;
        a = (ll) a * a % p;
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i ++)
    {
        int a, k, p;
        
        scanf("%d%d%d", &a, &k, &p);
        
        printf("%d\n", qki(a, k, p));
    }
    
    return 0;
}