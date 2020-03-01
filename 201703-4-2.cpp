#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct ArcNode
{
    int x;
    int y;
    int weight;
} AN;

/**
 * method sort�������ڱȽϽṹ���cmp����
 * params
 *  a, b ���Ƚϵ���������
 */
bool compare(AN a, AN b)
{
    return a.weight < b.weight;
}

/**
 * ���鼯
 */
class UF
{
private:
    int *parent;
    int *sum;

public:
    UF() {}
    UF(int n)
    {
        parent = new int[n + 1];
        sum = new int[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            sum[i] = 1;
        }
    }
    ~UF()
    {
        delete[] parent;
        delete[] sum;
    }
    void Union(int x, int y)
    {
        int xp = Find(x);
        int yp = Find(y);
        if (sum[xp] > sum[yp])
        {
            parent[yp] = xp;
            sum[xp] += sum[yp];
        }
        else
        {
            parent[xp] = yp;
            sum[yp] += sum[xp];
        }
    }
    /**
     * ����find��������ʹ��·��ѹ������Ȼ�÷ֻ�ֻ��85
     */ 
    int Find(int p)
    {
        while (p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    bool isConnected(int x, int y)
    {
        return Find(x) == Find(y);
    }
};

int main()
{
    /**
     * ����ʹ�ò��鼯��˼��
     * �������ΰ���Ȩֵ��������Ȼ�����β���
     * ֱ�� 1 n ��������
     */
    vector<AN> G;
    AN an;
    int n, m;
    cin >> n >> m;
    UF uf(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> an.x >> an.y >> an.weight;
        G.push_back(an);
    }
    sort(G.begin(), G.end(), compare);
    for (AN g : G)
    {
        uf.Union(g.x, g.y);
        if (uf.isConnected(1, n))
        {
            cout << g.weight;
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}