#include <iostream>
#include <vector>
#define MAXN 100005
using namespace std;

typedef struct ListNode
{
    int weight;
    int index;
} LN;

int n, m;
int vis[MAXN] = {0};
int min_time = 1000000;

/**
 * params
 *  G �ڽӱ�
 *  start ��ǰ��ʼ��
 *  end ��ֹ��
 *  path[] ��ǰ·��
 *  top ��ǰ�ݹ�Ĳ���
 */
void findAllPath(vector<LN> G[], int start, int end, LN path[], int top)
{
    if (start == end)
    {
        int max_weight = 0;
        for (int i = 1; i < top; ++i)
        {
            max_weight = (max_weight > path[i].weight) ? max_weight : path[i].weight;
        }
        min_time = (max_weight < min_time) ? max_weight : min_time;
    }
    else
    {
        for (LN n : G[start])
        {
            if (!vis[n.index])
            {
                vis[n.index] = 1;
                path[top] = n;
                findAllPath(G, n.index, end, path, top + 1);
                vis[n.index] = 0;
            }
        }
    }
}

int main()
{
    /**
     * �������dfs������·����˼�� 
     */

    cin >> n >> m;
    int x, y;
    vector<LN> G[n + 1];
    LN ln;
    //�����ڽӱ�
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> ln.weight;
        ln.index = x;
        G[y].push_back(ln);
        ln.index = y;
        G[x].push_back(ln);
    }

    //Ѱ������·��
    LN path[n];
    path[0].index = 1;
    vis[1] = 1;
    findAllPath(G, 1, n, path, 1);
    cout << min_time;
    system("pause");
    return 0;
}