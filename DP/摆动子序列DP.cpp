// 摆动子序列 DP。
//上升 下降交替；
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int h[N];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        cin >> h[i];
    }

    int up = 1;
    int down = 1;

    for(int i = 2; i <= n; i ++)
    {
        if(h[i] > h[i - 1])
        {
            up = down + 1;
        }

        else if(h[i] < h[i - 1])
        {
            down = up + 1;
        }
    }

    cout << max(up, down);

    return 0;
}