#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityelements(nums);
    cout << result << endl;
    return 0;
}
