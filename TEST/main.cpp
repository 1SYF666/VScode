#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"

int main()
{
    vector<int> prices = {7,6,4,3,1};
    int result = maxprofit2_dp(prices);
    cout << result << endl;
    return 0;
}
