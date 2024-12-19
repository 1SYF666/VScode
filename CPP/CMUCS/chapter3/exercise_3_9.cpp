long shift_left4_rightn(long x, long n)
{
   x <<= 4;
   x >> n;
   return x;
}

/*
x in %rdi, n in %rsi
scale2:
   leaq  (%rdi,%rdi,4),  %rax
   leaq  (%rax,%rsi,2),  %rax
   leaq  (%rax,%rdx,8),  %rax
   ret
*/

/*
   x in %rdi,    y in %rsi,    z in %rdx,
*/
