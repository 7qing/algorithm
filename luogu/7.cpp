#include<iostream>
using namespace std;
class neuron
{
public:
    int C=0,U=0;
     bool out;
    neuron(int C,int U):C(C),U(U){};
    neuron(const neuron &A):C(A.C),U(A.U){};
    ~neuron(){delete []this;};
};
class path
{
public:
    int w;
    neuron *n1,*n2;
    path(int w,neuron *n1,neuron *n2):w(w),n1(n1),n2(n2) {};
    void man();
    ~path() {delete []this;};
};
void path::man(){
    if(!n1->out)
        n2->C+=w*n1->C;
}

int main(){
    int m,n,k;
    cin>>m>>n;
    neuron *neu[m];
    path *pa[n];
    for (int i = 0; i < m; i++)
    {
        int x,y; cin>>x>>y;
        neu[i]=new neuron(x,y);
        if(neu[i]->C==0)
            neu[i]->out=true;
        else
            neu[i]->out=false;
    }
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        pa[i]=new path(z,neu[x-1],neu[y-1]);
        pa[i]->man();
    }
    for (int i = 0; i < m; i++)
    {
        if(neu[i]->out&&neu[i]->C>0)
        {
            cout<<i+1<<" "<<neu[i]->C-neu[i]->U<<endl;
            k++;
        }
        else if(k==0&&i==m-1)
            cout<<"NULL";
        else
            continue;
    }
    
    system("pause");
    return 0;
}




