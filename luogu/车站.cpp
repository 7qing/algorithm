#include<iostream>
using namespace std;
struct num
{
    int a1;
    int b1;
    num operator+(const num &n1)
    {
        num n2;
        n2.a1 = a1 + n1.a1;
        n2.b1 = b1 + n1.b1;
        return n2;
    }
};

int main(void)
{
    int a, n, m, x,y,k;
    cin >> a >> n >> m >> x;
    num *c1 = new num[n];
    num *d1 = new num[n];
    c1->a1 = a;
    c1->b1 = 0;
    (c1 + 1)->a1 = 0;
    (c1 + 1)->b1 = 1;
    d1->a1 = a;
    d1->b1 = 0;
    *(d1 + 1) = *d1;
    for (int i = 2; i < n-1;i++)
    {
        *(c1 + i) = *(c1 + i - 1) + *(c1 + i - 2);
        *(d1 + i) = *(d1 + i - 1) + *(c1 + i - 2);
    }
    y = (m - (d1 + n - 2)->a1) / (d1 + n - 2)->b1;
    k = (d1 + x - 1)->a1 + (d1 + x - 1)->b1*y;
    cout << k;
    delete[] c1,d1;
}