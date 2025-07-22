#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"
#include "Island.h"
#include "Productexceptself.h"

int main()
{
    vector<int> prices = {-813,82,-728,-82,-432,887,-551,324,-315,306,-164,-499,-873};
    int result = lengthOfLTS_bf(prices);
    cout << result << endl;
    return 0;
}
