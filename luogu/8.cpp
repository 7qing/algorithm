#include<iostream>
#include<algorithm>
using namespace std;
class gold
{
public:
    int left,right,number;
    gold(int left,int right,int number):left(left),right(right),number(number){};
    gold(const gold &A):left(A.left),right(A.right){};
    ~gold(){delete[]this;};
};
int main()
{
    int n,minsum=INT16_MAX;
    int h;
    cin>>n;
    gold *hs[n+1];
    int hm[n+1];
    for (int i = 0; i <=n; i++)
    {
        int a,b;
        cin>>a>>b;
        hs[i]=new gold(a,b,i);
        hm[i]=i;
    }
    do
    {
        int m=1,sum=1;
        for (int i = 1; i <=n ; i++)
        {
            m*=hs[hm[i-1]]->left;
            int x;
            x=m/hs[hm[i]]->right;
            if(i==0)
            {
                continue;
            }
            else
            {
            sum=max(sum,x);
            }
        }
         minsum=min(sum,minsum);
    }while(next_permutation(hm+1,hm+n+1));
    cout<<minsum;
    system("pause");
    return 0;
}

