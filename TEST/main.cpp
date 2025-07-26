#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"
#include "Island.h"
#include "Productexceptself.h"
#include"TestQuestions.h"
#include"Uncrosslines.h"

int main()
{
    // vector<int> prices1 = {1};
    // vector<int> prices2 = {-2,-1};
    string prices1 = "intention";
    string prices2 = "execution";
    int result = minDistance_72dp(prices1,prices2);
    cout << result << endl;
    return 0;
}
