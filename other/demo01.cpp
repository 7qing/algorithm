#include<iostream>
using namespace std;

class Base
{
private:
public:
    Base(/* args */){cout<<"Base start:\n";}
    ~Base(){cout<<"Base finish\n";}
};

class Derviced
{
private:
public:
    Derviced(/* args */){cout<<"Derviced start\n";}
    ~Derviced(){cout<<"Dervice finish\n";}
    Derviced(const Derviced &n1) {cout<<"fuzhi start\n";}
};

int main(int argc, char const *argv[])
{
    Base n1;
    Derviced n2;
    return 0;
}



