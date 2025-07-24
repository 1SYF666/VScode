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
    vector<int> prices1 = {3};
    vector<int> prices2 = {3,3,2};
    // string prices1 = "abcde";
    // string prices2 = "ace";
    int result = maxUncrossedLines_bf(prices1,prices2);
    cout << result << endl;
    return 0;
}
