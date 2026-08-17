// 已经知道前序遍历和后序遍历，求二叉树的个数
// 这是结论
// 如果前序遍历和后序遍历的某一段子树的根节点相同，那么该子树的左右子树可以交换位置，因此该子树的二叉树个数为2
// 比如前序中相邻两个pre[i], pre[i+1] //后序中..., pre[i+1], pre[i], ...
// 那么pre[i]只有一个孩子  数量*2；
/*#include <iostream>
#include <string>

using namespace std;

int main()
{
    string pre, post;

    cin >> pre >> post;

    long long ans = 1;

    for(int i = 0; i + 1 < pre.size(); i++)
    {
        for(int j = 1; j < post.size(); j++)
        {
            if(pre[i] == post[j] &&
               pre[i + 1] == post[j - 1])
            {
                ans *= 2;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}*/

// 递归版
// 在dfs中传入的参数是前序遍历和后序遍历的左右边界，分别是pl, pr, ql, qr    

#include <iostream>
#include <string>

using namespace std;

string pre, post;

long long ans = 1;

void dfs(int pl, int pr, int ql, int qr)
{
    if(pl >= pr)
        return;

    char root = pre[pl];

    // 前序中根后面的第一个节点
    char x = pre[pl + 1];

    int k = ql;

    while(post[k] != x)
        k++;

    // 左侧第一棵子树的大小
    int len = k - ql + 1;

    // 如果第一棵子树占满除根外所有节点
    // 说明当前根只有一个孩子
    if(len == pr - pl)
    {
        ans *= 2;

        dfs(pl + 1, pr, ql, qr - 1);
    }
    else
    {
        // 第一棵子树
        dfs(pl + 1,
            pl + len,
            ql,
            k);

        // 第二棵子树
        dfs(pl + len + 1,
            pr,
            k + 1,
            qr - 1);
    }
}

int main()
{
    cin >> pre >> post;

    int n = pre.size();

    dfs(0, n - 1, 0, n - 1);

    cout << ans << endl;

    return 0;
}