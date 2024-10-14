#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int l,size;
    int max_;
    int min_=0;
    cin>>l;
    cin>>size;
    int *it=new int[size];
    for (int i = 0; i < size; i++)
    {
        cin>>it[i];
    }
    if(size==0)
    {
        cout<<"error";
        return -1;
    }
    else if(size==1)
    {
        min_=min(it[0],l+1-it[0]);
        max_=max(it[0],l+1-it[0]);
    }
    else
    {
    sort(it,it+size);
    for(int i=0;i<size;i++)
    {
        min_=max(min(it[i],l+1-it[i]),min_);
    }
    max_=max(max(it[0],l+1-it[0]),max(it[size-1],l+1-it[size-1]));
    }
    cout<<min_<<" "<<max_;
    system("pause");
    return 0;
}
// #include<iostream>
// #include<cmath>
// #include<algorithm>
// using namespace std;
// const int size = 5005;
// int a[size];
// int main()
// {
//     int L,N;
//     cin>>L>>N;
//     if (!N) 
//     {
//         cout<<"0 0"<<endl;
//         return 0;
//     }
//     for (int i=1;i<=N;i++) cin>>a[i]; 
//     sort(a+1,a+N+1); 
//     int max_time,min_time;
//     for (int i=1;i<=N;i++)
//         min_time=max(min(a[i],L+1-a[i]),min_time); 
//     max_time=max(L+1-a[1],a[N]); 
                                 
//     cout<<min_time<<' '<<max_time<<endl;
//     return 0;
// }