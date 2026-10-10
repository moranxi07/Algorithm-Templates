#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll qpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

ll fac[105];
ll infac[105];

ll C(int n, int m)
{
    if(m < 0 || m > n) return 0;
    return fac[n] * infac[m] % mod * infac[n - m] % mod;
}

ll A(int n, int m)
{
    return fac[n] * infac[n - m] % mod;
}

int main()
{
    fac[0] = 1;

    for(int i = 1; i <= 100; i ++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }

    infac[100] = qpow(fac[100], mod - 2);

    for(int i = 100; i >= 1; i --)
    {
        infac[i - 1] = infac[i] * i % mod;
    }

    string s[5];

    while(cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4])
    {
        ll dp[32] = {};
        dp[0] = 1;

        for(int hero = 0; hero < 100; hero ++)
        {
            ll ndp[32];

            for(int mask = 0; mask < 32; mask ++)
            {
                ndp[mask] = dp[mask];
            }

            for(int mask = 0; mask < 32; mask ++)
            {
                for(int player = 0; player < 5; player ++)
                {
                    if(!(mask >> player & 1) && s[player][hero] == '1')
                    {
                        int nmask = mask | (1 << player);

                        ndp[nmask] += dp[mask];

                        if(ndp[nmask] >= mod)
                        {
                            ndp[nmask] -= mod;
                        }
                    }
                }
            }

            for(int mask = 0; mask < 32; mask ++)
            {
                dp[mask] = ndp[mask];
            }
        }

        ll pick = dp[31];

        ll ans = pick;

        ans = ans * A(95, 5) % mod;
        ans = ans * C(90, 5) % mod;
        ans = ans * C(85, 5) % mod;

        cout << ans << endl;
    }

    return 0;
}