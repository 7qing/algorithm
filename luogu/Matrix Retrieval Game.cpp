#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int matrix[81][81];

void print(__int128_t x){
    stack<int>o;
    while(x)o.push(x%10),x/=10;
    while(!o.empty())cout<<o.top(),o.pop();
    cout<<endl;
}
int main()
{
    __int128_t sum=0;
    int m,n;
    cin>>m>>n;
    int *itbegin[m];
    int *itend[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }   
        itbegin[i]=&matrix[i][0];
        itend[i]=&matrix[i][n-1];
    }
    for (int j = 0; j < n; j++)
    {
            for (int i = 0; i < m; i++)
            {
                if(*itbegin[i]<*itend[i])
                {
                    sum+=pow(2,j+1)*(*itbegin[i]);
                    itbegin[i]++;
                }
                else
                {
                    sum+=pow(2,j+1)*(*itend[i]);
                    itend[i]--;
                }
            }
    }
    print(sum);
    system("pause");
    return 0;
}
// #include<cstdio>
// struct int128
// {
//     long long hig;
//     long long low;
// };//定义int128
// int n,m;
// long long p=1e18;//作mod用
// int128 ans,f[85][85][85],a[85][85];
// int128 max(int128 a,int128 b)
// {
// 	if(a.hig>b.hig) return a;
// 	if(a.hig<b.hig) return b;//高位比较
// 	if(a.low>b.low) return a;
// 	if(a.low<b.low) return b;//低位比较
// 	return a;//相等时还要返回一个值
// }
// int128 operator + (int128 a,int128 b)//重载运算符
// {
//     int128 k;
//     k.low=0,k.hig=0;
//     k.low=a.low+b.low;
//     k.hig=k.low/p+a.hig+b.hig;//防止溢出
//     k.low%=p;
//     return k;
// }
// int128 operator * (int128 a,int b)
// {
// 	int128 k;
// 	k.low=0,k.hig=0;
// 	k.low=a.low*b;
// 	k.hig+=k.low/p+b*a.hig;//与上同理
// 	k.low%=p;
// 	return k;
// }
// int main()
// {
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     for(int j=1;j<=m;j++)
//         scanf("%lld",&a[i][j].low);
// 	for(int i=1;i<=n;i++)
//     for(int len=0;len<m;len++)
//     for(int l=1;l+len<=m;l++)//区间动态规划
//             f[l][l+len][i]=max(f[l+1][l+len][i]+a[i][l],f[l][l+len-1][i]+a[i][l+len])*2;
//     for(int i=1;i<=n;i++)
//     	ans=ans+f[1][m][i];
//     if(ans.hig==0)	printf("%lld",ans.low);
//     else	printf("%lld%018lld\n",ans.hig,ans.low);
// }