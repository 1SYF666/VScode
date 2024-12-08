int bis(int x, int m) // 位设置
{

}
int bic(int x, int m) // 位清除
{

}
int bool_or(int x, int y)
{
   int result = bis(x, y);
   return result;
}

int bool_xor(int x, int y)
{
   int or_result = bis(x, y);               // 计算x | y
   int and_result = bic(x, ~y);             // 计算x & y
   int result = bic(or_result, and_result); // 计算(x|y) & ~(x&y)
   return result;
}


