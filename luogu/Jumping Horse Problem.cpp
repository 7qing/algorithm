#include <iostream>
using namespace std;
const int nx[8]={1,2,-1,-2,2,1,-2,-1};
const int ny[8]={2,1,-2,-1,-1,-2,1,2};
int minsum=9999;
void lookfor(int(*f)[8],int x,int y,int sum=-1)
{
    sum++;  
    if(sum>minsum)
        return;
    if (x>=0&&x<8&&y>=0&&y<8)
    {
        if(f[x][y]==2&&sum<minsum)
            minsum=sum;
        else if(f[x][y]==0)
        {
            f[x][y]=1;
            for (int i = 0; i < 8; i++)
            {
                lookfor(f,x+nx[i],y+ny[i],sum);
            }
            f[x][y]=0;
        }
        else return;
    }
    else return;
}
int main()
{
    int f[8][8]={0};
    int hx,hy,mx,my;
    cin>>hx>>hy;
    cin>>mx>>my;
    f[mx][my]=2;
    lookfor(f,hx,hy);
    cout<<minsum;
    system("pause");
    return 0;
}
