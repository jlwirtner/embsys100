/*******************************************************************************
File name       : swapCharAsm.s
Description     : Assembly language function for swapping two chars
*******************************************************************************/   
    
    PUBLIC swapCharAsm       // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharAsm
Description     : Calls C code to swap two chars; 
                  divides its input argument by 2
C Prototype     : int div2Asm(val)
                : Where val is the value to be divided by 2
Parameters      : R0: Address of char1
                : R1: Address of char2
Return value    : R0
*******************************************************************************/  
  
swapCharAsm
    PUSH {R4,R5}         // save variable registers
    LDRB R4,[R0]         // load value of char1 into R4
    LDRB R5,[R1]         // load value of char2 into R5
    STRB R5,[R0]         // store value in R5 at char1's memory location
    STRB R4,[R1]         // store value in R4 at char2's memory location
    MOV R0, #1           // Put 1 in return register 

    TEQ R4, R5           // Test equivalance of R4 and R5 - set Z flag in APSR if equal
    IT EQ                // Execute the next instruction if the Z flag is set in the APSR
    MOVEQ R0, #0         // Move #0 into R0 if Z flag is set in APSR to return 0 if chars are identical
    
    POP {R4,R5}          // Restore variable registers
    BX LR                // return (with function result in R0)

    END
