// Manacher算法求最长回文子串长度
// p[i]表示以t[i]为中心的最长回文半径，t是预处理后的字符串
// 解释一下:
// 1. 预处理：在每个字符之间插入分隔符（如#），并在开头和结尾也插入分隔符。
//    这样可以将奇数长度和偶数长度的回文统一处理。
// 例如，字符串"abc"预处理后变为"#a#b#c#"，字符串"abba"预处理后变为"#a#b#b#a#"。
// 2. 利用对称性：如果i在当前最右回文的范围内，那么p[i]至少等于min(p[mirror], right - i)，其中mirror是i关于center的对称点。
// 3. 中心扩展：从i开始向两边扩展，直到不再是回文为止，更新p[i]。
// 4. 更新最右回文：如果i + p[i] > right，则更新center和right为i和i + p[i]。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int manacher(const string& s)
{
    // 1. 预处理：插入分隔符
    string t = "#";
    for(char c : s)
    {
        t += c;
        t += "#";
    }
    
    int n = t.size();
    vector<int> p(n, 0);  // 回文半径
    
    int center = 0;  // 当前最右回文的中心
    int right = 0;   // 当前最右回文的右边界
    int maxLen = 0;
    
    for(int i = 0; i < n; i++)
    {
        // 2. 利用对称性初始化
        if(i < right)
        {
            int mirror = 2 * center - i;  // i 关于 center 的对称点
            p[i] = min(right - i, p[mirror]);
        }
        
        // 3. 中心扩展
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
              t[i - p[i] - 1] == t[i + p[i] + 1])
        {
            p[i]++;
        }
        
        // 4. 更新最右回文
        if(i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
        
        // 5. 更新答案
        maxLen = max(maxLen, p[i]);
    }
    
    return maxLen;  // p[i] 就是原字符串中的回文长度
}

int main()
{
    string s;
    getline(cin, s);
    
    cout << manacher(s) << endl;
    
    return 0;
}