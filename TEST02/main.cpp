#include <iostream>
#include <vector>
#include <list>
#include "hot100_v1.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i =0;i<n;i++)
    {
        cin>>nums[i];
    }
    ListNode* head = creatList(nums);
    head = leetcode206(head);
    ListNode* cur = head;
    while(cur)
    {
        cout<<cur->val<<" ";
        cur =cur->next;
    }

    
    return 0;
}
