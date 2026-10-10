/*
gcd->min
lcm->max
下面先推导公式
有恒等式：lcm(gcd(a, c), b) = gcd(lcm(a, b), lcm(b, c))
也就是lcm(x, y) = y;
什么时候lcm(x, y) = y呢？当且仅当y整除x，也就是y % x == 0

这个公式怎么来的呢？我们知道lcm(a,b) = a * b / gcd(a,b)

下面先设vp(a) 是 p的指数，也就是a中有多少个p的因子
那么我们有vp(lcm(a,b)) = max(vp(a), vp(b))
vp(lcm(b, c)) = max(vp(b), vp(c))
vp(gcd(a, c)) = min(vp(a), vp(c))

所以原式lcm(gcd(a,c),gcd(b,c)) 指数也就是 min(max(vp(a), vp(b)), max(vp(b), vp(c))) = max(min(vp(a), vp(c)), vp(b))
min(vp(a), vp(c)) = vp(gcd(a,c))
max(vp(b), min(vp(a), vp(c))) = vp(lcm(vp(b),gcd(a,c)))
也就是min(max(vp(a), vp(b)), max(vp(b), vp(c))) = max(min(vp(a), vp(c)), vp(b)) = vp(lcm(b, gcd(a,c)))
就是min(max(vp(a), vp(b)), max(vp(b), vp(c))) = vp(lcm(b, gcd(a,c)))
左边指数等于右边指数也就是
gcd(lcm(a,c),b) = lcm(gcd(a,b),gcd(b,c))
*/

// 看题
/*
B. Crimson Triples

time limit per test

1 second

memory limit per test

256 megabytes

*Chills run down your spine...*

— Terraria

After summoning the next boss — The Brain of Cthulhu, you noticed that it surrounds itself with n eyes, numbered from 1 to n. In one attack, The Brain of Cthulhu chooses a triple of eyes (not necessarily distinct) with numbers (a,b,c). The triple of eyes is called *crimson* if and only if the following property holds:

gcd∗(lcm†(a,b),lcm(b,c))=gcd(a,c),

To defeat the boss, you want to know how many ways The Brain of Cthulhu can choose a crimson triple of eyes. The triples of eyes (a1,b1,c1) and (a2,b2,c2) are considered different if a1≠a2, or b1≠b2, or c1≠c2.

∗gcd(x,y) denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers x and y.

†lcm(x,y) denotes the [least common multiple (LCM)](https://en.wikipedia.org/wiki/Least_common_multiple) of integers x and y.

**Input**

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows.

The only line of each test case contains one integer n (1≤n≤2⋅105) — the number of eyes of The Brain of Cthulhu.

It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

**Output**

For each test case, output one integer — the number of ways to choose a crimson triple of eyes.

**Example**

**Input**

**Copy**

```
3
```

1

2

20

**Output**

**Copy**

```
1
```

5

612

**Note**

In the first test case, there is 1 possible crimson triple: (1,1,1).

In the second test case, there are 5 possible crimson triples: (1,1,1), (1,1,2), (2,1,1), (2,1,2), (2,2,2).
*/

// 目的就是将原式gcd∗(lcm†(a,b),lcm(b,c))=gcd(a,c) 
// 利用lcm(gcd(a, c), b) = gcd(lcm(a, b), lcm(b, c)) 这个公式转化为
// lcm(gcd(a,c),b) = gcd(a,c)
// 也就是gcd(a,c) % b == 0；
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        ll ans = 0;

        for(ll b = 1; b <= n; b++)
        {
            ll cnt = n / b; // a和c的个数;
            ans += cnt * cnt;
        }

        cout << ans << '\n';
    }

    return 0;
}
