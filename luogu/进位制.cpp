#include<iostream>
#include<cstring>
using namespace std;
static int n;
static int k;
static int h;
int mode;
class num
{
public:
    int val;
    string name;
};
int main(void)
{
    cin >> n;
    n++;
    num **it = new num *[n];
    for(int i = 0; i < n;i++)
    {
        *(it + i) = new num[n];
        for (int j = 0; j < n;j++)
            cin >> (*(it + i) + j)->name;
    }
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
        {
            if(it[i][j].name==it[i][0].name&&it[0][j].name==it[i][j].name)
                it[i][0].val = 0;
            if(sizeof(it[i][j].name)==2)
            {
                if(it[i][j].name[0]==it[i][0].name[0])
                {
                    k = i; break;
                }
                else
                {
                    k = j; break;
                }
            }
        }
    it[k][0].val = 1;
    h = k;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n;j++)
        {
            if(it[j][0].name==it[k][h].name)
            {
                it[j][0].val = 1 + it[h][0].val;
                h = j;
            }
        }
    }
    for (int i = 1; i < n; i++)
        cout << it[i][0].name << "=" << it[i][0].val << " ";
    cout << endl
         << n - 1;
}