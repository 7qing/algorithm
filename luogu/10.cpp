#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int N;
class num
{
public:
    int n[999]={0}, len = 0;
    num man();
    num operator+(const num &n1)
    {
        num n2;
        n2.len = max(len, n1.len) + 1;
        for (int i = 0; i < n2.len; i++)
        {
            n2.n[i + 1] += (n[i] + n1.n[i]) / N;
            n2.n[i] += (n[i] + n1.n[i]) % N;
        }
        for (int i = n2.len - 1; n2.n[i] == 0;--i,--n2.len) {}
        return n2;
    }
};
  ostream& operator<<(ostream &out,const num& x)  
    {
    for(int i=x.len-1;i>=0;--i)
        cout<<x.n[i];
    return out;
    }
num num::man()
{
    num n2;
    n2.len = len;
    for (int i = len-1; i>=0;--i)
        n2.n[len - 1 - i] = n[i];
    return n2;
}
bool cmp( num n1)
{
    int i = 0;
    for (; i < n1.len; ++i)
    {
        if(n1.n[i]!=n1.n[n1.len-1-i])
            return false;
    }
    if(i==n1.len)
        return true;
}
int main(void)
{
    int j;
    string n;
    cin >> N;
    cin >> n;
    num ans;
    num sum;
    for (auto i = n.cbegin(); i != n.cend();i++)
    {
        ans.n[ans.len++] = *i-48;
    }
    int s=0;
    while (1)
    {
        if(s<30)
        {
            sum = ans + ans.man();
            if(cmp(sum))
            {
                cout << "STEP="<<s+1;
                break;
            }
            else
                ans = sum;
            s++;
        }
        else
        {
            cout << "Impossible!";
            break;
        }
    }
}