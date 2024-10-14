#include <iostream>
#include <iomanip>
using namespace std;
class gas_st
{
public:
    float distance;
    float price;
    gas_st(float distance,float price): distance(distance),price(price) {}
    ~gas_st();
};
gas_st::~gas_st()
{}
gas_st *station[8];

int main(){
    float gas,gas0,gasdis,distance,gasprice,sumprice;
    int n;
    cin>>distance>>gas0>>gasdis>>gasprice>>n;
    n+=1;
    float maxdis=gasdis*gas0;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    if (n==1)
    {
        if (maxdis>distance)
            cout<<(distance/gasdis)*gasprice;
        else
            cout<<"No Solution";  
    }
    else
    {
        station[0]=new gas_st(0,gasprice);
        station[n]=new gas_st(distance,0);
    for (int i = 1; i <n; i++)
    {
        float x,y;
        cin>>x>>y;
        station[i]=new gas_st(x,y);
    }
    sumprice=gas0*gasprice;
    for (int i = 1; i <=n; i++)
        {
            if(station[i]->distance-station[i-1]->distance<maxdis)
            {
                if (i==n)
                {
                    sumprice-=(gas0-(station[n]->distance-station[n-1]->distance)/gasdis)*station[n-1]->price;
                    break;
                }
                if(station[i-1]->price<station[i]->price)
                {
                    sumprice+=(station[i]->distance-station[i-1]->distance)/gasdis*station[i]->price;
                    cout<<sumprice<<" ";
                }
                else{
                    sumprice+=(station[i]->price-station[i-1]->price)*gas0+(station[i]->distance-station[i-1]->distance)/gasdis*station[i]->price;
                    cout<<sumprice<<" ";
                }
            }
            else
                cout<<"No Solution";
        }
    cout<<sumprice;
    system("pause");
    return 0;
    }
}