/*
Q37 (了解即可) how to convert a string representation on infix (operator is in the 
middle of two operands) to RPN (Reverse Polish notation)
3 + 2 * (4 + 1) == 13
Stack (bottom) ||: + *
3⇒ output: 3 2 4 1 + * +
13
优先级1： ()
优先级2： * /
优先级3: ＋ output:
3241+*+
stack (bottom): || +*
*/