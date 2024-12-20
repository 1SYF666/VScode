/*
x in %rdi, y in %rsi , qp in %rdx , rp in %rcx
uremdiv:
   movq %rdx,%r8
   movq %rdi,%rax
   movl $0,%edx
   divq %rsi
   movq %rax,(%r8)
   movq %rdx,(%rcx)
   ret
*/

void uremdiv(unsigned long x, unsigned long y, unsigned long *qp, unsigned long *rp)
{
   unsigned long q = x / y;
   unsigned long r = x % y;
   *qp = q;
   *rp = r;
}
