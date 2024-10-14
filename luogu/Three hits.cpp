#include<iostream>
#include<cstring>
int num[10];
using namespace std;
void man(int a)
{
    int x;
    while (a != 0)
    {
        x = a % 10;
        a = a / 10;
        num[x]++;
    }
}
bool xf()
{
    int i = 1;
    for (; i < 10; i++)
    {
        if(num[i]!=1)
            return false;
    }
    if(i==10)
    return true;
}
int main(void)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9;k++)
            {
                int a = i * 100 + j * 10 + k;
                int b = 2 * a;
                int c = 3 * a;
                man(a);
                man(b);
                man(c);
                if(xf())
                    cout << a << " " << b << " " << c << endl;
                memset(num,0,sizeof(num));
            }
        }
    }
}