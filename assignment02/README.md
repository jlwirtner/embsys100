# **Assingment 2**

## Problem 1
**a.)** -2147483648\
**b.)** 0x80000000\
**c.)** The N and V flags are both set because the value is negative and an overflow occurred. The value is now negative because the most significant bit of 0x80000000 is 1 and because counter is a signed integer, the 
the processor interprets this as a negative number stored using two's complement. The overflow flag is set because the number overflowed from the maximum positive number, 0x7FFFFFFF, to a negative number.

## Problem 2
**a.)** The value becomes 0.\
**b.)** The N and V flags are both not set. This is because counter is now 0x00000000. Therefore the most significant bit is 0 and the value is positive. The V flag is not set because 0xFFFFFFFF is -1 using two's complement
 and incrementing -1 simply gives 0.

## Problem 3
**a.)** 2147483648\
**b.)** The N and the V flag are both set again even though the integer is unsigned. I think that the flags are set because the V is set if the most significant bit changes from 0 to 1, no matter what. And the N is set if
 the most significant bit is 1, no matter what. It is up to the code to interpret the value as an unsigned integer.

## Problem 4
**a.)** 0\
**b.)** The N and V are both not set again. The N is unset for the same reason as 2b, but this time the V flag is not set because the C flag is set instead. This means that a carry occurred instead of an overflow, meaning 
the value did not overflow past some semantic limit, but instead needs more bits to properly hold the value.

## Problem 5
**a.)** The counter variable now has global scope.\
**b.)** The counter variable is no longer visable in the "locals" view\
**c.)** The counter variable can now be found in the "Memory" view\
**d.)** The address for the counter variable is 0x20000000\

## Problem 6
**a.)** Counter = 4\
**b.)** The counter variable has global scope and is the only variable stored in memory (RAM). Therefore we can assume the variable's memory address will be the first avaible address for SRAM, which is 0x20000000. In 
main, we create a local variable of type int * and assign it the value 0x20000000. We then dereference the pointer and increment the value stored at that memory location three times. Since we manually assigned the 
pointer to be the first available address in RAM, this will increment the counter variable three times. We then increment the counter variable directly, ending with a value of 4.


## Problem 7
**a.)** 0x20000000\
**b.)** The counter variable is stored in RAM - its value is forgotten when the board is powered off.\
**c.)** counter = 4


