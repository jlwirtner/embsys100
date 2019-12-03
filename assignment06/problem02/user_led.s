/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay  // delay() is defined outside this file.

    PUBLIC control_user_led         // Exports symbols to other modules

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
Function Name   : control_user_led
Description     : - Uses Peripheral registers at base 0x4000.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  
GPIOA_ODR EQU 0x40020014

control_user_led
    // <TODO: Add your code for the function here>
    PUSH {R4, LR}       // Save Registers and LR
    LDR R2, =GPIOA_ODR  // LOAD GPIOA_ODR address from global constant
    LDR R4, [R2]        // Load current GPIOA_ODR value
    CMP R0, #0          // Compare R0 to 0
    BLE off             // If R0 == 0, branch to off section
    ORR R4, R4, #0x20   // Set bit that turns port 5 on
    STR R4, [R2]        // Update GPIOA_ODR
    BL exit             // Branch to exit section
off:
    BIC R4, R4, #0x20   // Clear bit that turns port 5 on
    STR R4, [R2]        // Update GPIOA_ODR 
    BL exit             // Branch to exit section
exit:
    MOV R0, R1          // Move duration input to input for delay
    BL delay            // Execute delay function
    POP {R4, LR}        // Restore Risgters and LR
    BX LR               // Return
    END
