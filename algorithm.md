
http://csis.pace.edu/~murthy/ProgrammingProblems/16_Evaluation_of_infix_expressions

operand 操作数; 运算元;
operator 算子; 运算符;

In the following, “process” means, 

(i) pop operand stack once (value1) 

(ii) pop operator stack once (operator) 

(iii) pop operand stack again (value2) 

(iv) compute value2 operator  value1
为什么要 value2 op value1 呢？

(v) push the value obtained in operand stack.


算法:


直到表达式的结束，得到一个 operand/operator 就做下面的某一步

(a) 如果读到一个数，push 到 operand stack 里面去

(b) 如果读到一个运算符, 并且 operator stack 是空的, push 到 operator stack 里面去

(c) 如果读到一个运算符, 并且 operator stack 不是空的, 而且读到的运算符的优先级大于栈顶运算符的优先级, push 到 operator 堆栈里面去

(d) 如果读到 "(", push 到 operator stack 里面去

(e) 如果读到 ")", 做 process, 直到遇到对应的 "(", pop 掉这个 "(" 忽略这个 "("

(f) 如果上面的的条件都不满足, 做 process

没有输入的东西了就一直做 process 直到 operator stack 变成空的。最后留在 operand stack 的值就是最终的结果。
