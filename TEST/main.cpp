#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"

int main()
{
    string str = "coletleetleet";
    string substr = "leet";
    int result = cmpstr_bf(str,substr);
    cout << result << endl;
    return 0;
}
