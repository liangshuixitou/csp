#include <iostream>
using namespace std;

int ans = 0;
const int MOD = 1e4;
void mod(int &d)
{
    if (d > MOD)
        d -= MOD;
}

void recursion(int a, int b)
{
    int z = abs(a - b);
    ans++;
    mod(ans);
    for (int i = 1; i < z; ++i)
    {
        recursion(b, i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        recursion(n, i);
    cout << ans;
    system("pause");
}
