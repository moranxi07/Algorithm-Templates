// |⋃_{i=1}^n A_i| = Σ_{k=1}^n (-1)^{k-1} Σ_{1≤i₁<...<iₖ≤n} |A_{i₁} ∩ ... ∩ A_{iₖ}|

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 20;
int n, m;
int p[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++) cin >> p[i];
    
    int res = 0;
    
    for(int i = 1; i < 1 << m; i ++)
    {
        int t = 1;
        int cnt = 0;
        for(int j = 0; j < m; j ++)
        {
            if(i >> j & 1)
            {
                cnt ++;
                if((ll)t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                
                t *= p[j];
            }
        }
        
        if(t != -1)
        {
            if(cnt % 2) res += n / t;
            else res -= n / t;
        }
    }
    
    cout << res << endl;
    
    return 0;
}