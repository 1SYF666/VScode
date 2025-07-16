#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"

int main()
{
    vector<int> prices = {6,1,3,2,4,7};
    int result = maxprofit3_bf2(prices);
    cout << result << endl;
    return 0;
}
