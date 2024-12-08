
#include <string.h>
/* warning:This is buggy code */
int strlonger(char *s, char *t)
{
   return strlen(s) - strlen(t) > 0;
}


int strlonger(char *s, char *t)
{
   strlen(s) > strlen(t);
}
