#include<iostream>
using namespace std;
const int HX[]={0,2,1,-1,-2,1,2,-2,-1};
const int HY[]={0,1,2,-2,-1,-2,-1,1,2};
long long ll[22][22];
bool h[22][22];
int hx,hy,bx,by;
int main()
{   
    cin>>bx>>by>>hx>>hy;
    hx+=2;hy+=2;bx+=2;by+=2;
    ll[1][2]=1;
    ll[2][1]=0;
    for (int i = 0; i < 9; i++)
    {
        h[hx+HX[i]][hy+HY[i]]=true;
    }
    for (int i = 2; i <= bx; i++)
    {
        for (int n = 2; n <= by; n++)
        {
            if(h[i][n])
            {
                ll[i][n]=0;
                continue;
            }
            ll[i][n]=ll[i-1][n]+ll[i][n-1];
        }
    }
    cout<<ll[bx][by];
    
    system("pause");
    return 0;
}
