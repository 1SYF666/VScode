#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
int main()
{
    vector<int> coins = { 2};
    int amount = 3;
    int64_t result = INT64_MAX;
    coinchange_backtracking(coins,amount,0,0,result);
    result = (result==INT64_MAX)?-1:result;
    cout << result << endl;
    return 0;
}
