#include<iostream>
using namespace std;
string man(int n)
{
    string str1;
    int str[15];
    int len=0;
    do
    {
        str[len] = n % 2;
        n = n / 2;
        len++;
    }while(n != 0);
    for (int i = len-1; i >= 0; --i)
    {
        if(str[i]!=0)
        {
        if(i>1)
        {
            int x=0;
            str1.append("2(");
            str1.append(man(i));
            str1.append(")");
            for (int j = i-1; j >= 0;--j)
                if(str[j]!=0)
                    x++;
            if(x!=0)
                 str1.append("+");
        }
        if(i==1)
        {
            if(str[0]!=0)
                str1.append("2+");
            else
                str1.append("2");
        }
        if(i==0)
            str1.append("2(0)");
        }
    }
    return str1;
}

int main(void)
{
    int n;
    cin >> n;
    cout << man(n)<<endl;
}