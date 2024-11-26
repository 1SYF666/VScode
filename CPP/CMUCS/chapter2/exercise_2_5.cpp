#include "show.h"
void exercise_2_5()
{
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp,1);
    show_bytes(valp,2);
    show_bytes(valp,3);
}