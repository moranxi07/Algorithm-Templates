//无规定数量
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int res = 0;
    while(t --)
    {
        int a;
        cin >> a;
        
        res = res ^ a;
        
    }
    
    if(res != 0) cout << "Yes" << endl;
    
    else cout << "No";
    
    return 0;
}