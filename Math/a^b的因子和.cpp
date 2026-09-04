// 若mod为质数
// 那么p的逆元为qki(p, mod - 2)；
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int mod = 9901;

ll qki(ll a, ll b)
{
    a %= mod;
    ll res = 1;

    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ans = 1;

    for(ll p = 2; p * p <= a; p ++)
    {
        if(a % p == 0)
        {
            ll e = 0;
            while(a % p == 0)
            {
                a /= p;
                e ++;
            }

            ll n = e * b;
            ll s;

            // 因为p是质数, 所以p^0 + p^1 + ... + p^n = (p^(n + 1) - 1) / (p - 1)
            if(p % mod == 1)// 1 + 1 + ... + 1 = n + 1;（p^0 + p^1 + ... + p^n）% mod = (n + 1) % mod
            {
                s = (n + 1) % mod;
            }

            // 正常等比数列求和
            else
            {
                s = (qki(p, n + 1) - 1 + mod) % mod;
                s = s * qki(p - 1, mod - 2) % mod;
            }

            ans = ans * s % mod;
        }
    }

    if(a > 1)
    {
        ll p = a;
        ll n = b;
        ll s;

        if(p % mod == 1)
        {
            s = (n + 1) % mod;
        }

        else
        {
            s = (qki(p, n + 1) - 1 + mod) % mod;
            s = s * qki(p - 1, mod - 2) % mod;
        }

        ans = ans * s % mod;
    }

    cout << ans << endl;

    return 0;
}