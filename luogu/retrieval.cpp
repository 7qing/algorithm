#include<iostream>
using namespace std;
int n, i, j, l, k, x, y, s;
int d[55][55], f[55][55][55][55];
int main() 
{
 cin>>n;
 while(1)
 {
    cin>>x>>y>>s;
    if(x==0&&y==0&&s==0)
        break;
    d[x][y] = s;
 }
 for(i = 1; i <= n; i++)
 for(j = 1; j <= n; j++)
 for(l = 1; l <= n; l++)
 for(k = 1; k <= n; k++) 
 {
  f[i][j][l][k] = max(max(f[i - 1][j][l - 1][k], f[i][j - 1][l][k-1]), max(f[i - 1][j][l][k - 1], f[i][j - 1][l - 1][k])) + d[i][j];
  if(i != 1 && j != k) f[i][j][l][k] += d[l][k];
  }
 cout<<f[n][n][n][n];
 system("pause");
 return 0;
}