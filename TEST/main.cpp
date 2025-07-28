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
    // vector<int> prices2 = {1,1,1};
    string prices1 = "cbbd";
    string prices2 = "ros";
    int result = longestPalindromeSubseq_dp(prices1);
    cout << result << endl;
    return 0;
}
