#include <iostream>
using namespace std;
bool check(int v[], int t, int n)
{
    int i = 0;
    while (i < t)
    {
        if (v[i] < v[t])
        {
            break;
        }
        i++;
    }
    if (i == t)
    {
        return false;
    }
    i = t + 1;
    while (i < n)
    {
        if (v[i] > v[t])
        {
            break;
        }
        i++;
    }
    if (i == n)
    {
        return false;
    }
    return true;
}
int main()
{
    int n, res = 0;
    cin >> n;
    int v[1005];
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if (check(v, i, n))
            res++;
    }
    cout << res;
    system("pause");
    return 0;
}