#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"
#include "Island.h"

int main()
{
    vector<int> prices = {2, 1, 4};
    int result = maxProfit5_dp(prices);
    cout << result << endl;
    return 0;
}
