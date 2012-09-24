About Embedded IQ Floats

Embedded IQ Floats it's a library to perform floating point operaionts in IQ format, considering variable types of 16 bits. It is targeted mainly for microcontrollers but it can be used in PC's or any other device that supports C language.

The user can perform the basic operations:
-	Addition.
-	Substraction.
- 	Multiplication.
-	Division.

The bits for the fractional part can be configured, from 0 to 16, being 0 a none fractional portion and 16 a full fractional number. The operations support different formats in the operands and another format for the result, giving the developer flexibility to accomplish its tasks being precise. 

Note that the library does not check for overflow errors, it is left for the developer to consider this when using this library.