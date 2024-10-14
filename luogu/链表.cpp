#include<iostream>
using namespace std;
class list
{
    public:
        int num;
        list *it;
        list(int num,list*next=nullptr): num(num),it(next) {}
};
int main(void)
{
    list *list1 = nullptr;
    double n;
    cout << "please put in the number:";
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int m;
        cin >> m;
        list1 = new list(m, list1);
    }
        list *ptr = list1;
    while (ptr != nullptr)
    {
        cout << ptr->num << " "; 
        ptr = ptr->it;
    }
}