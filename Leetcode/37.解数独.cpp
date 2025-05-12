/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
private:
    bool backtracking(vector<vector<char>>&board)
    {
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                    continue;
                for(char k = '1';k<='9';k++)
                {
                    if(isValid(i,j,k,board))
                    {
                        board[i][j] = k;            // 放置
                        if(backtracking(board)) return true;
                        board[i][j] = '.';          // 回溯
                    }
                }

                return false;  // 9个数都试完了，都不行，那么就返回false
            }
        }
        return true;
    }

    bool isValid(int row,int col,char val,vector<vector<char>>& board)
    {
        // 行
        for(int i =0;i<9;i++)
        {
            if(board[row][i]==val)
                return false; 
        }

        // 列
        for(int j =0;j<9;j++)
        {
            if(board[j][col]==val)
                return false; 
        }

        // 九宫格
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        for(int i =startrow;i<startrow+3;i++)
        {
            for(int j = startcol;j<startcol+3;j++)
            {
                if(board[i][j]==val){
                    return false;
                }
            }
        }

        // 
        return true;

    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

