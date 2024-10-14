#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
int n;
cin >> n;
int **it = new int* [n];
for (int i = 0; i < n;i++)
{
it[i] = new int[n];
it[0][i] = (i + 1) % n;
cout << it[0][i] << " ";
}
cout << endl;
for (int i = 1; i < n; i++)
{
for (int j = 0; j < n;j++)
{
it[i][j] = it[i - 1][(j + 1) % n];
cout << it[i][j]<<" ";
}
cout << endl;
}
delete[] it;
}
// cin>>n;
// int **it=new int *[n];
// man[n][m]
