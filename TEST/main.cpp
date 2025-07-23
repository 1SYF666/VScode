#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"
#include "Besttime.h"
#include "Island.h"
#include "Productexceptself.h"
#include"TestQuestions.h"

int main()
{
    vector<int> prices1 = {0,0,0,0,0};
    vector<int> prices2 = {0,0,0,0,0};
    int result = findLength_bf(prices1,prices2);
    cout << result << endl;
    return 0;
}
