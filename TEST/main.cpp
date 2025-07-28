#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"
#include "Island.h"
#include "Productexceptself.h"
#include "TestQuestions.h"
#include "Uncrosslines.h"

int main()
{
    vector<int> prices1 = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> prices2 = {1,1,1};
    // string prices1 = "cbbd";
    // string prices2 = "ros";
    // int result = maxSlidingWindow_bf(prices1,3);
    vector<int> result = maxSlidingWindow_bf(prices1, 3);
    cout << "[";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] <<( (i + 1 < result.size()) ? "," : "");
    cout << "]";
    return 0;
}
