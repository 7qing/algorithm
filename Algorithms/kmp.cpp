#include <iostream>

using namespace std;

int main()
{
    int m, n;
    char ne[100];
    string p, s;
    cin >> m >> p >> n >> s;

    ne[0] = -1;
    for (int i = 1, j = -1; i < m; i++)
    {
        while (j >= 0 && p[j + 1] != p[i])
            j = ne[j];
        if (p[j + 1] == p[i])
            j++;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < n; i++)
    {
        while (j != -1 && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m - 1)
        {
            cout << i - j << ' ';
            j = ne[j];
        }
    }
    // 输出next数组
    // cout<<endl<<"next[]: "<<endl;
    // for(int i = 0; i < m; i++) cout<<ne[i]<<' ';
}