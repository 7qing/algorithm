#include <iostream>
#include <iostream>
using namespace std;
class M
{
private:
    
public:
    M(string name) {name=name;}
    ~M();
    string name;
    int number;
};

M::~M()
{}
M *maritx[15][15]
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ni++)
    {   
        for (int j = 0; j < n; j++)
        {
            string m;
            cin>>m;
        maritx[i][j]=new M(m);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(maritx[0][1]->name==maritx[1][0]->name&&maritx[0][1]==maritx[1][1]->name)
                maritx[1][0]->number=0;
            if
        }
        
    }
    
    system("pause");
    return 0;
}
