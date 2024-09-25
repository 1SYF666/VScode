#include <iostream>
#include "max.h"
using namespace std;

int main()
{
    cout<<"hello world!"<<endl;
    int a;
    int b;
    cin>>a;
    cin>>b;
    int c = max(a,b);
    cout<<a<<" 和 "<<b<<" 的最大值是 "<<c<<endl;

    return 0;
}