#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const string &A,const string &B) 
{
	return A+B>B+A;  
}
int main(void)
{
	int n;
	cin>>n;
    vector<string> S(n);
    for (int i = 0; i < n; ++i)
        cin>>S[i];
    vector<string>::iterator it = S.begin();
    sort(it, it + n, cmp);
    for(int i=0;i<n;++i)
		cout<<S[i];
}