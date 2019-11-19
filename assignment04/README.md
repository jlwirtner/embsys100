# **Assignment 4**

## Problem 1
**b.)** When using bit banding to turn the LED on, the compiler genterated three assembly instructions.First, a LDR.N operation loads into register 2 the value that is pointed to in memory by the value stored in the PC register plus an offset of 0x2C (LDR.N R2, [PC, #0x2c]). Then, a MOVS operation moved the value #1 into register 3 (MOVS R3, #1). Then a STR operation stores the value located in register 3 to the location in memory that is pointed to by the value stored in register 2 (STR R3, [R2]).
\
\
When using bit banding to turn the LED off, the compiler generated two instructions in assembly. First a MOVS operation moves the value #0 to register 0 (MOVS R0, #0). Then a STR operation stores the value located in register 0 to the location in memory that is pointed to by the value stored in register 2 (STR R5, [R2]). This generated one less instruction because register 2 already contained the pointer to the GPIOA output bit band register.
\
\
**c.)** When turning on the LED by writing directly to the register, the compiler generates four instrusctions. First, a LDR.N operation loads into register 2 the value that is pointed to in memory by the value stored in the PC register plus an offset of 0x34 (LDR R2, [PC, #0x34]). Secondly, a LDR operation loads into register 3 the value that is pointed to in memory by the value stored in register 2 (LDR R3, [R2]). Then, an ORRS.W operation performs a bitwise OR between the value stored in register 3 and #32, then writes this result to register 3 (ORRS.W R3, R3, #32). Lastly, a STR operation stores the value located in register 3 to the location in memory that is pointed to by the value stored in register 2 (STR R4, [R2]).
\
\
When turning off the LED by writing directly to the register, the compiler generates three instrusctions. First, a LDR operation loads into register 0 the value that is pointed to in memory by the value stored in register 2 (LDR R0, [R2]). Then, a BICS.W operation takes the value stored in register 0 and performs a bitwise AND with the one's complement of #32, and then writes the result to register 0 (BICS.W R0, R0, #32). This is known as a bit clear operation. Lastly, a STR operation stores the value located in register 0 to the location in memory that is pointed to by the value stored in register 2 (STR R0, [R2]). This generated one less instruction because register 2 already contained the pointer to the GPIOA output register.

## Problem 2

**a.)** When a funcitons is called from within another function, the calling function passes variables by first moving them into the lower registers using a MOVS operation. Then, before the called function starts executing instructions for the code contained within it, it first moves the values stored in these lower registers into R4-R11 which are used to store variables.
\
\
**b.)** When a functions is called that requires more argumentes the compiler generates extra assembly instructions to handle passing the extra parameters to the function. First a MOVS operation moves one of the argument's value into register 0, then a STR operation stores the value in R0 to the location pointed to by the stack pointer, plus an offset. This offset is determined by how many extra variables there are and decreses each time (decrementing stack) until it reaches 0. The rest of the variables are then moved to the lower registers again like they were for functions with fewer arguments.
\
\
**c.)** Then inside the called function, LDR operations load the parameters that were stored in the stack into registers 4-11. The values that were stored in the lower registers are left there to be manipulated from within the function.
\
\
**d.)** I noticed that the offsets for the STR and LDR operations were different. If a parameter was stored in the stack using the operation STR R0, [SP, #0x4] then it was loaded using LDR R* [SP, #0x14], if it was stored with an offset of 0xC, it was loaded with an offset of 0x1C.
\
\
The functions I created to test this just took parameters and incremented them. I noticed that the values that were passed using the lower registers were just incremented and left in place. The values that were passed by loading them from the stack, on the other hand, were immediately stored back in the stack after they were incremented.
