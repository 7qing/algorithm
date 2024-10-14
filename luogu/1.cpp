#include<iostream>
#include<vector>
using namespace std;

vector<node>trip;

class node{
public:
    float V;
    float money;
    float distance;
    node(float distance,float money): distance(distance),money(money),V(0) {}
};

int main()
{
    float sumdistance,money,n,gasD,sumV,sum,distance=0;
    cin>>sumdistance>>sumV>>gasD>>money>>n;
    for (int i = 0; i <= n; i++)
    {
        node A(distance,money);
        trip.push_back(A);
        if(i!=n) cin>>distance>>money;
    }
    //init
    node A(sumdistance,0);
    trip.push_back(A);
    sum=sumV*trip[0].money;
    trip[0].V=sumV;

    for (int i = 1; i <= n+1; i++)
    {
        float needV=(trip[i].distance-trip[i-1].distance)/gasD;
        trip[i].V =needV;
        sum+=needV*trip[i].money;
        while (1)
        {
            float min=100000;
            int h=0;
            for (int k = 0; k < i; k++)
                if(trip[k].V !=0 && trip[k].money< min)
                {
                    min=trip[k].money;
                    h=k;
                }
            if(trip[h].V > needV)
            {
                trip[h].V -= needV;
                break;
            }
            else if(min == 100000)
            {
                cout<<"No Solution";
                break;
            }
            else
            {
                needV-= trip[h].V;
                trip[h].V = 0;
            }
        }
    }

    for (int i = 0; i <=n; i++)
        if(trip[i].V != 0)
        {
            sum -=trip[i].V*trip[i].money;
        }

    cout<<sum;
    return 0;
}