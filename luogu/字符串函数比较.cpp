#include<iostream>
using namespace std;
int strcmp(const char*str1,const char*str2)
{
    while ((*str1) && (*str1 == *str2))  
    {  
        str1++;  
        str2++;  
    }  
    if (*(unsigned char*)str1 > *(unsigned char*)str2)  
    {  
        return 1;  
    }  
    else if (*(unsigned char*)str1 < *(unsigned char*)str2)  
    {  
        return -1;  
    }  
    else  
    {  
        return 0;  
    }    
}
int main(void)
{
    int n = 0;
    char *a = "lzh";
    char *b = "yyx";
    n = strcmp(a, b);
    if (n == 1) cout << "a>b";
    else if(n==0) cout << " a=b";
    else cout << "a<b";
}