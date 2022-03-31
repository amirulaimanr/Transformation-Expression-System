# Transformation-Expression-System
Transformation Expression Program

Infix transformation to Postfix and Prefix and Postfix Program

The algorithms are:

1. Create an empty stack and an empty postfix output string/stream.

2. Scan the infix input string/stream left to right.

3. If the current input token is an operand, simply append it to the output string 
   (note the examples above that the operands remain in the same order).

4. If the current input token is an operator, pop off all operators that have equal or 
   higher precedence and append them to the output string; push the operator onto the stack.

5. The order of popping is the order in the output. If the current input token is 
   '(', push it onto the stack If the current input token is ')', pop off all operators
   and append them to the output string until a '(' is popped; discard the '('. 
   If the end of the input string is found, pop all operators and append them to the output string.

6. This algorithm doesn't handle errors in the input, although careful analysis of 
   parenthesis or lack of parenthesis could point to such error determination.

First thing first, this program has been built with C++ programming language. 
The main objective of this program was built is to make a conversion from infix 
expression to other expression in easier way and faster using stack. Conversion 
of infix to postfix expression can be done elegantly using two precedence function. 
Each operator is assigned a value (larger value means higher precedence) which depends 
upon whether the operator is inside or outside the stack. Also the right and left 
associativity for different operators can be handled by varying it’s values in the 
two precedence functions.
