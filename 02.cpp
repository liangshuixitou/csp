#include <iostream>
using namespace std;

bool check(int i)
{
    if (i / 10 == 0)
        return true;
    int pre = i % 10;
    i /= 10;
    int thi = i % 10;
    while (i)
    {
        if (pre < thi)
            return false;
        pre = i % 10;
        i /= 10;
        thi = i % 10;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (check(i))
            count++;
    }
    cout << count;
    system("pause");
    return 0;
}