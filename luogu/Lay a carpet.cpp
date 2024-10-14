#include <iostream>
#include <vector>
using namespace std;
class M
{
    public:
        bool man(int x1,int y1);
        int x;
        int y;
        int a;
        int b;
};
bool M::man(int x1,int y1){
    if(x<=x1&&x1<=x+a&&y<=y1&&y1<=y+b)
    {
        return true;
    }
    else
        return false;
}

int main(){
    int size=0,sum=0;
    cin>>size;
    M *it;
    it=new M[size];
    for (int i = 0; i < size; i++)
    {
        cin>>it[i].x>>it[i].y>>it[i].a>>it[i].b;
    }
    int x1,y1;
    cin>>x1>>y1;
    for (int i = 0; i < size; i++)
    {
        if(it[i].man(x1,y1))   
            sum=i+1;
    }
    if(sum==0)
        sum=-1;
    cout<<sum;
    delete []it;
    system("pause");
    return 0;
}