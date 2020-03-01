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
 * method sort函数用于比较结构体的cmp参数
 * params
 *  a, b 带比较的两个函数
 */
bool compare(AN a, AN b)
{
    return a.weight < b.weight;
}

/**
 * 并查集
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
     * 这里find函数必须使用路径压缩，不然得分会只有85
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
     * 本题使用并查集的思想
     * 将边依次按照权值进行排序，然后依次插入
     * 直到 1 n 相连即可
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