#include <iostream>
#include <cstring>
using namespace std;
bool check(char s[], char ch)
{
    for (int i = 0; i < 5; ++i)
    {
        if (s[i] == ch)
            return true;
    }
    return false;
}
int main()
{
    int res = 0;
    char s[] = "aeiou";
    char in[105];
    std::cin >> in;
    int len = strlen(in);
    int i = 0;
    if (check(s, in[i++]))
    {
        cout << "no";
        //system("pause");
        return 0;
    }
    while (check(s, in[i]))
    {
        i++;
        if (i == len)
        {
            cout << "no";
            //system("pause");
            return 0;
        }
    }
    while (!check(s, in[i]))
    {
        i++;
        if (i == len)
        {
            cout << "no";
            //system("pause");
            return 0;
        }
    }
    while (check(s, in[i]))
    {
        i++;
        if (i == len)
        {
            cout << "yes";
            //system("pause");
            return 0;
        }
    }
    cout << "no";
    //system("pause");
    return 0;
}