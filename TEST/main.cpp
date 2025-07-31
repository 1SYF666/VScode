#include <iostream>
#include "Partitions.h"

int main()
{
    vector<int>nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int result = removeElement_doublepoint(nums,val);
    cout<<result<<endl;
    return 0;
}
