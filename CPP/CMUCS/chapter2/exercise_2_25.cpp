
/* warning: this funcion is buggy */
float sum_element(float a[],unsigned length)
{
   int i;
   float result = 0;
   for ( i = 0; i <= length-1; i++)
   {
      result+=a[i];
   }
   return result;
}

/* 
   这份函数没有内容错误
*/
float sum_element2(float a[],int length)
{
   int i;
   float result = 0;
   for ( i = 0; i <= length-1; i++)
   {
      result+=a[i];
   }
   return result;
}

/* 
   这种修改是建立在用户调用sun_elemenet3时长度不会输入负值得条件下
   计算数组之和，傻子才输入复数
*/
float sum_element3(float a[],unsigned length)
{
   int i;
   float result = 0;
   for ( i = 0; i < length; i++)
   {
      result+=a[i];
   }
   return result;
}

