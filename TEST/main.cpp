#include "Knapsack_Problem.h"

int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    vector<string> path;
    vector<vector<string>> subsets;
    path.clear();
    subsets.clear();
    backtracking4(strs, 0,path,subsets);
    cout<<subsets.size()<<endl;
    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << "\"" << subset[i] << "\"";
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
