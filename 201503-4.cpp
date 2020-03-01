#include <iostream>
#include <vector>
#define MAXN 20005
using namespace std;

int n, m;
vector<int> G[MAXN];
bool vis[MAXN];

/**
 * method bfs
 * return 最大距离
 * params:
 *  s 起始点
 *  t 距离s最远的点
 */
int bfs(int s, int *t)
{
    int queue[MAXN];
    int base = 0, top = 0, temp_top = 0, res = 0;
    for (int i = 1; i <= n + m; ++i)
    {
        vis[i] = 0;
    }
    vis[s] = 1;
    queue[top++] = s;
    while (top != base)
    {
        temp_top = top;
        for (int i = base; i < temp_top; ++i)
        {
            for (int j : G[queue[i]])
            {
                if (!vis[j])
                {
                    vis[j] = 1;
                    queue[top++] = j;
                }
            }
        }
        res++;
        base = temp_top;
    }
    *t = queue[top - 1];
    return res - 1;
}

int main()
{
    /**
     * 求树的直径问题
     * 借助贪心算法两次dfs或者bfs即可找出树的直径
     */
    int t, res;
    cin >> n >> m;

    for (int i = 2; i <= n + m; ++i)
    {
        cin >> t;
        G[i].push_back(t);
        G[t].push_back(i);
    }

    //第一次bfs找到距离其最远的点
    bfs(1, &t);
    //第二次求树的直径
    res = bfs(t, &t);
    cout << res;
    system("pause");
    return 0;
}