#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
struct fantastic     
{
    int len,s[9999];
    fantastic()
    {
        memset(s,0,sizeof(s));
        len=1;
    }
    fantastic operator=(const char*num)
    {
        len=strlen(num);
        for(int i=0;i<len;++i)
            s[i]=num[len-i-1]-'0';
        return *this;
    }
    fantastic operator=(const int num)
    {
        char a[9999];
        sprintf(a,"%d",num);
        *this=a;
        return *this;
    }
    fantastic (const int num)
    {
        *this=num;
    }
    fantastic (const char * num)
    {
        *this=num;
    }
    fantastic operator+(const fantastic &a)   
    {
        fantastic c;
        c.len=max(len,a.len)+1;              
        for(int i=0,x=0;i<c.len;++i)
        {
            c.s[i]=s[i]+a.s[i]+x;
            x=c.s[i]/10;
            c.s[i]=c.s[i]%10;
        }
        if(c.s[c.len-1]==0)
            --c.len;
        return c;
    }
    fantastic operator * (const fantastic &x)           
    {
        fantastic c;
        c.len=len+x.len;                
        for(int i=0;i<len;++i)
            for(int j=0;j<x.len;++j)
            {
                c.s[i+j]+=s[i]*x.s[j];
                c.s[i+j+1]+=c.s[i+j]/10;
                c.s[i+j]%=10;
            }
        if(c.s[c.len-1]==0)
            --c.len;
        return c;
    }
};
ostream& operator<<(ostream &out,const fantastic& x)  
{
    for(int i=x.len-1;i>=0;--i)
        cout<<x.s[i];
    return out;
}

int main()        
{
    int n;
    fantastic ans = 0, num = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        num=num*i;
        ans=ans+num;
    }
    cout<<ans<<endl;
}   
// #include<stdio.h>
// int main()
// {
//     int i,A[1005]={0},B[1005]={0},n,j;
//     scanf("%d", &n);
//     A[0]=B[0]=1;
//     for (i=2;i<=n;i++){
//         for (j=0;j<100;j++)
//             B[j]*=i;
//         for (j=0;j<100;j++)
//             if (B[j]>9){
//                 B[j+1] += B[j]/10;
//                 B[j]%=10;
//             }
//         for (j=0;j<100;j++){
//             A[j]+=B[j];
//             if (A[j]>9) {
//                 A[j+1] += A[j]/10;
//                 A[j]%=10;
//             }
//         }
//     }
//     for (i=100;i>=0&&A[i]==0;i--);
//     for (j=i;j>=0;j--) printf("%d", A[j]);
//     return 0;
// }