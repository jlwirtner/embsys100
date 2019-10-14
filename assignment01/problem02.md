# *Problem 2*

Why use two's complement to represent negative numbers?

## Simple Arithmetic

Storing negative numbers using two's complement allows negative numbers to be added using simple binary arithmetic (the same way you would add two positive numbers).
If negative numbers where stored using a sign and value representation, an extra step would be required to check the sign and determine if the operation is an addition or subtraction.

## Single Zero Representation

Two's complement only has one representation for zero, while sign and value representation has two (zero - 0000 and negative zero 1000).

## Simple Size Expansion

When storing numbers using two's complement, you can expand the size of the number by simply repeating the most significant digit.
Expanded the size of a negative number stored using sign and value representation would require an extra step.
You would first have to change the 1 representing the negative sign to a 0, then add the additional 0's, then add the final 1.

