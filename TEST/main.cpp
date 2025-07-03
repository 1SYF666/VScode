#include "Knapsack_Problem.h"

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int count = 0;
    backtracking3(0, 0, count, nums, target);
    cout << count << endl;
    return 0;
}
