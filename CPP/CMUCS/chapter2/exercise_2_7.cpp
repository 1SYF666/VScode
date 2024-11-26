#include "show.h"
#include<string.h>
void exercise_2_7()
{
   const char * s = "abcdef";
   show_bytes((byte_pointer)s,strlen(s));
}

int main()
{
     exercise_2_7();
}