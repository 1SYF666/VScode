#include <stdio.h>
// 从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。
/*
输入格式:输入一个整数 n。
输出格式:
    每行输出一种方案。
    同一行内的数必须升序排列，相邻两个数用恰好 1 个空格隔开。
    对于没有选任何数的方案，输出空行。
    本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。
数据范围:1≤n≤15
*/

const int N = 15;
int X[N];
void dfs(int index, int n)
{
    // 0 -- 待选；1 -- 选；2 -- 不选
    if (index == n)
    {
        for (int i = 0; i <= n; i++)
        {
            if (X[i] == 1)
                printf("%d", i + 1);
        }
        printf("\n");
        return ;
    }

    // 不选
    X[index] = 2;
    dfs(index + 1, n);
    X[index] = 0;

    // 选择
    X[index] = 1;
    dfs(index + 1, n);
    X[index] = 0;
}
/* 接雨水

*/





