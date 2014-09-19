/*
Q36. how to evaluate a Reverse Polish notation (逆波兰表达式)
Reverse Polish notation is a postfix mathematical notation where the operands
of any particular operator immediately precede the operator.
* For example, 3 + 4 would be written 3 4 + and 2 * (4 + 1) would be written 
as 4 1 + 2 * or 2 4 1
+ *
*
* Takes a list of strings representing either operators or operands and returns
* the result of a reversepolish
notation calculation on them
* Sample output:
* {"4", "1", "+", "2", "*"} >
10 ((4 + 1) * 2)
* {"5", "8", "4", "/", "+"} >
7 (5 + (8 / 4))
* Supported operators are +, ,
*, and /
* @param ops the series of operators and operands to operate on
* @return a Double equal to the result of the calculation
Reverse Polish notation advantage: we can calculate the final result without worrying 
about the precedence of the operator. 3 + 35 + ( )….
*/