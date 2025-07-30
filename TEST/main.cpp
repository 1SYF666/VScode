#include <iostream>
#include "Partitions.h"

int main()
{

    int n = 4;
    vector<vector<string>> result = solveNQueens(n);

    int row = result.size();
    int col = result[0].size();
    cout << "[";
    for (int i = 0; i < row; i++)
    {
        cout<<"[";
        for (int j = 0; j < col; j++)
        {
            cout<<"\"";
            for(int k = 0;k<result[i][j].size();k++)
            {
                cout<<result[i][j][k];
            }
            cout<<"\""<<((j+1<col)?",":"");
        }
        cout<<"]"<<((i+1<row)?"\n":"");
    }
    cout << "]";

    return 0;
}
