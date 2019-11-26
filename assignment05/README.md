# Assignment 5

## Problem 1
**a.)** The main fucntion stores local variables on the CSTACK when defining them.
After defining xPtr the SP is the location at which xPtr is stored and the value at that location is the address for x.
After defining yPtr the SP is the location at which yPtr is stored and the value at that location is the address for y, with xPtr being the value store just after it (decrementing stack).
Just prior to calling the swap_pointer() function, main first moves the current stack pointer (SP) into R1, and then moves the SP plus an offset (previous value in stack) into R0.
\
\
**b.)** R0 contains the address at which the pointer to x is stored (pointer to a pointer) and R1 contains the address at which the pointer to y is stored (pointer to a pointer).
\
\
**c.)** Before: ![problem 1 before](pictures/p1_before.png)
\
After: ![problem 1 after](pictures/p1_after.png)

## Problem 2
**e.)** ![problem 2](pictures/p2.png)

## Problem 3
**d.)** ![problem 3](pictures/p3.png)

## Problem 4
**c.)** Different characters: ![problem 4 different characters](pictures/p4_diff.png)
\
Same characters: ![problem 4 same characters](pictures/p4_same.png)
