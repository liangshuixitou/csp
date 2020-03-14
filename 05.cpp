#include <iostream>
using namespace std;

int n, m, k;
char G[1005][1005];
char G2[1005][1005];
void dfs(int t, int i, int j)
{
    if (t != k + 1)
    {
        G[i][j] = 'g';
        if (i < n)
            dfs(t + 1, i + 1, j);
        if (i > 1)
            dfs(t + 1, i - 1, j);
        if (j < m)
            dfs(t + 1, i, j + 1);
        if (j > 1)
            dfs(t + 1, i, j - 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> G[i][j];
            G2[i][j] = G[i][j];
        }
    }
    cin >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (G2[i][j] == 'g')
                dfs(0, i, j);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << G[i][j];
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}
