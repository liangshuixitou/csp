#include <iostream>
#include <vector>
#define MAXN 20005
using namespace std;

int n, m;
vector<int> G[MAXN];
bool vis[MAXN];

/**
 * method bfs
 * return ������
 * params:
 *  s ��ʼ��
 *  t ����s��Զ�ĵ�
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
     * ������ֱ������
     * ����̰���㷨����dfs����bfs�����ҳ�����ֱ��
     */
    int t, res;
    cin >> n >> m;

    for (int i = 2; i <= n + m; ++i)
    {
        cin >> t;
        G[i].push_back(t);
        G[t].push_back(i);
    }

    //��һ��bfs�ҵ���������Զ�ĵ�
    bfs(1, &t);
    //�ڶ���������ֱ��
    res = bfs(t, &t);
    cout << res;
    system("pause");
    return 0;
}