#include <iostream>
using namespace std;
int a[51][51], f[51][51][51][51];
int m, n;

int max(int i, int j, int k, int l){
    int m = max(i, j), n = max(k, l);
    return max(m, n);
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    f[1][1][1][1] = 0; 
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = i+1; k <= m; k++){
                for(int l = 1; l < j; l++){
                    f[i][j][k][l] = max(
                        f[i][j-1][k][l-1],
                        f[i][j-1][k-1][l],
                        f[i-1][j][k-1][l],
                        f[i-1][j][k][l-1]
                    )+a[i][j]+a[k][l];
                }
            }
        }
    }
    cout << f[m-1][n][m][n-1] << endl;
     system("pause");
    return 0;    
}

