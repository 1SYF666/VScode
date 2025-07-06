#include "Knapsack_Problem.h"
#include "Knapsack_Problem2.h"
#include "Daily_temperature.h"

int main()
{
    vector<int>weight ={1,3,4};
    vector<int>value ={15,20,30};
    int maxweight = 4;
    int result = 0;
    backtracking_exp1(weight,value,maxweight,0,0,result);
    cout << result << endl;

    return 0;
}
