#include <iostream>
#include "Spiralmatrix.h"

void PrintMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    cout << "[";
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << ((j + 1 < col) ? "," : "");
        }
        cout << "]" << ((i + 1 < row) ? "," : "");
    }
    cout << "]";
}
void PrintArray(vector<int> &array)
{
    int n = array.size();
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ((i + 1) < n ? "," : "");
    }
    cout << "]";
}

int main()
{
    vector<int> val = {7,8,9,11,12};
    int result = firstMissingPositive_bf(val);
    cout << result << endl;
    return 0;
}
