#include <iostream>
#include "findKthlargest.h"
#include "Knapsack_Problem2.h"
#include "Climbstairs.h"
#include "Majority_elements.h"

int main()
{
    string str = "aaaaaaa";
    vector<string> worddict = {"aaaa","aaa"};
    bool result = wordbreak_brutal(str, worddict);
    if (result)
        cout << "1" << endl;
    cout << result << endl;
    return 0;
}
