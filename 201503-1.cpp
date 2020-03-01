#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int f[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> f[i][j];
        }
    }
    for (int j = m - 1; j >= 0; --j)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << f[i][j];
            if (i != n - 1)
                cout << " ";
        }
        if (j != 0)
            cout << "\n";
    }
    system("pause");
    return 0;
}