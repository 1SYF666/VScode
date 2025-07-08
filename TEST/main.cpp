#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
int main()
{
    int amount = 0;
    vector<int> coins = {7};
    int result =0;
    result = backtracking_exp2(coins, amount,0);
    cout << result << endl;
    return 0;
}
