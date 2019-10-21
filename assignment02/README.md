# **Assingment 2**

## Problem 1
**a.)** 536870912
**b.)** 0x20000000
**c.)** None of the flags are set becuase none of the condions for the flags were meet. The most significant bit (not byte) is still 0, so it does not read it as a negative number. The number is not zero. There was no 
carry bit, overflow, or saturation either - therefore the Z, C, V, and Q flags are all zero.

## Problem 2
**a.)** The value becomes 0.
**b.)** The zero (Z) and carry flags (C) are set in the APSR. This is because we were at the maximum value of a 32 bit integer and we incremented by one. We therefore roll over back to zero, setting the zero flag. The carry flag
 is set because the value rolled over. All other flags are zero.

## Problem 3
**a.)** 536870912 (same as problem 1)
**b.)** None of the flags were set for the same reasons described in 1-c.

## Problem 4
**a.)** 0
**b.)** The zero and carry flags are set for the same reasons described in 2-b.

## Problem 5
**a.)** The counter variable now has global scope.
**b.)** The counter variable is no longer visable in the "locals" view
**c.)** The counter variable can now be found in the "Memory" view
**d.)** The address for the counter variable is 0x20000000

## Problem 6
**a.)** Counter = 4
**b.)** The counter variable has global scope and is the only variable stored in memory (RAM). Therefore we can assume the variable's memory address will be the first avaible address for SRAM, which is 0x20000000. In 
main, we create a local variable of type int * and assign it the value 0x20000000. We then dereference the pointer and increment the value stored at that memory location three times. Since we manually assigned the 
pointer to be the first available address in RAM, this will increment the counter variable three times. We then increment the counter variable directly, ending with a value of 4.


## Problem 7
**a.)** 0x20000000
**b.)** The counter variable is stored in RAM - its value is forgotten when the board is powered off.
**c.)** counter = 4


