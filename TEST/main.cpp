#include <iostream>
#include "Spiralmatrix.h"

int main()
{
    int val = 1;
    vector<vector<int>> result = generatematrix(val);
    int row = result.size();
    int col = result[0].size();

    cout << "[";
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < col; j++)
        {
            cout << result[i][j] << ((j + 1 < col) ? "," : "");
        }
        cout << "]"<<((i + 1 < row) ? "," : "");
    }
    cout << "]";

    return 0;
}
