# OH-Script 

## Introduction 

OpenHoldem’s scripting language is very similar to the C programming
expression syntax. If you already know and understand C programming then
you have an advantage in that the OH scripting language should be very
familiar. This section is largely based off of Ray Bornert’s original
WinHoldem C-tutorial (<http://www.winholdem.net/help/help-c.html>).

## Syntax 

The general syntax for OpenHoldem formulas is same as that of the C
programming language. However, the formulas are strict *r-values* (right
side of an assignment expression), meaning that there is no assignment
operator.

## Comments

C-syntax means of cource C(++)-comments, too. Comments will improve your
code and will make it more easy to read and understand, both for
yourself and for other people. Make use of them!

    // This is a C-style-comment
    // till the end of the line.

    /* 
       and this is a C++-style
       multi-line-comment.
    */

## Data Types

OH-Script is a programming language without typing. All values are
stored as (double) floating point values on the expression stack,
regardless if they are floating points, integers, booleans (logicals) or
bit-vectors. For bitwise operations the values are first internally
converted to integer values and then the operator is applied.

If a value is interpreted as numerical or boolean depends solely on the
context. A common beginners mistake is to mix up boolean and numerical
values, boolean and numerical operators.

## Rounding Errors

One of the main problems with floating-points are the inevitable
rounding errors (<http://floating-point-gui.de/>).. Rounding errors
occur for numerical calculations, but also for conversions of
floating-point-numbers from decimal format (OH-script) to the internal
binary representation
(<http://en.wikipedia.org/wiki/Binary_numeral_system>).

Rounding errors are especially annoying when you compare two numbers,
that should be equal from an exact mathematical point of view but are
only nearly in practice.

To overcome this problem OpenHoldem uses approximative comparision for
relational and equality operators (\< \<= \> \>= == !=). It will treat
two numbers as “equal”, when they differ by not more than $10^{^{-6}}$.
This applies of course only to OH-script; DLL–users have to care about
correct rounding themselves!

## Boolean Logic

A boolean expression is composed of logical operators (not, and, or,
xor) and operands. All boolean operands have only two values - true and
false. Each logical operand has a very well defined operation upon the
operand(s) in the expression, with a very well defined result. When any
numeric value is used in conjunction with a logical operator, any zero
values are considered to be false (0) and any non-zero values are
considered to be true (1). If the numeric value in question is not zero
then it is considered to be true for boolean purposes. Reams of material
have been written on boolean logic
(<a href="http://en.wikipedia.org/wiki/Boolean_logic "
class="uri">http://en.wikipedia.org/wiki/Boolean_logic </a>).

## Operators 

These operators are listed in order of precedence.

| Category       | Operator(s)                      | Associativity |
|:---------------|:---------------------------------|:--------------|
| Exponentiation | \*\* ln (not standard ANSI C)    | Right to Left |
| Unary          | ! ~ - ‘                          | Right to Left |
| Multiplicative | \* / %                           | Left to Right |
| Additive       | \+ -                             | Left to Right |
| Bitwise Shift  | \<\>                             | Left to Right |
| Relational     | \< \> \<= \>=                    | Left to Right |
| Equality       | == != \~~                        | Left to Right |
| Bitwise        | AND &                            | Left to Right |
| Bitwise        | XOR ^                            | Left to Right |
| Bitwise        | OR \|                            | Left to Right |
| Logical        | AND &&                           | Left to Right |
| Logical        | XOR ^^ (not standard ANSI C)     | Left to Right |
| Logical        | OR \|\|                          | Left to Right |
| Conditional    | ?:                               | Right to Left |
| Group          | () \[\] {} (not standard ANSI C) | Left to Right |

- Exponentiation Power \*\* (not ANSI-C) a \*\* b Standard algebraic
  exponentiation on a and b. a is raised to the power of b.

- Natural Log ln (not ANSI-C) ln a Standard algebraic natural log of a a
  == e \*\* (ln a)

- Natural Log Base e (not ANSI-C) e == 2.71828182845905

- Unary A unary operator takes a single operand.

- Logical NOT ! False when the operand is true. True when the operand is
  false. a  !a false true true false 0 1

- Bitwise NOT ~ Logical NOT operation on a bit by bit basis.  

  | expression |          binary result           |
  |:----------:|:--------------------------------:|
  |     a      | 11001001011101010110010101111010 |
  |     ~a     | 00110110100010101001101010000101 |

- Negation - A good example is the minus sign when it is used to alter
  the sign of a value. Example: a + b / -4 The minus sign in front of
  the 4 is a unary minus.

- Bit Count ‘ (not ANSI-C) Provides a count of the number of bits set in
  any integer value. Here are 3 examples of the number of bits that are
  set in some 32-bit integer numbers.  

  |                a                | ‘a  |
  |:-------------------------------:|:---:|
  | 0000000000000000000000000000000 |  0  |
  | 0000000000000100000000000000000 |  1  |
  | 0000010000000100000000000010000 |  3  |
  | 1111111111111111111111111111111 | 32  |

- Multiplicative Multiply \* a \* b Standard algebraic multiplication on
  a and b.

- Divide / a / b Standard algebraic division on a and b.

- Modulo % a % b Standard algebraic modulo on a and b.

- Percentage % a % b The result will be (a / 100) \* b. The percentage
  operator got introduced with OpenPPL. OpenHoldem will assume that “%”
  inside an OH-script function means the modulo-operator and that “%”
  inside an OpenPPL-function (with WHEN-conditions) means the
  percentage-operator.

- Additive Add + a + b Standard algebraic addition on a and b.

- Subtract - a - b Standard algebraic subtraction on a and b.

- Bitwise Shift Left \<\< Slides the entire bit pattern to the left by N
  bits. Note that the leftmost bits are simply dropped and that the
  rightmost bits are filled with 0’s. The shift magnitude is used as
  modulo 32, meaning that any shift N that is specified in excess of 32
  bits has a N%32 operation performed prior to the shift.  

  | expression |          binary result           |
  |:----------:|:--------------------------------:|
  |     a      | 11001001011101010110010101111010 |
  |   a\<\<1   | 10010010111010101100101011110100 |
  |   a\<\<7   | 10111010101100101011110100000000 |
  |  a\<\<31   | 00000000000000000000000000000000 |
  |  a\<\<32   | 11001001011101010110010101111010 |

- Bitwise Shift Right \>\> Slide the entire bit pattern to the right by
  N bits. Note that the rightmost bits are dropped and that the leftmost
  bits are filled with 0’s. The shift magnitude is used as modulo 32,
  meaning that any shift N that is specified in excess of 32 bits has a
  N%32 operation performed prior to the shift. expression binary
  result.  

  | expression |          binary result           |
  |:----------:|:--------------------------------:|
  |     a      | 11001001011101010110010101111010 |
  |   a\>\>1   | 01100100101110101011001010111101 |
  |   a\>\>7   | 00000001100100101110101011001010 |
  |  a\>\>31   | 00000000000000000000000000000001 |
  |  a\>\>32   | 11001001011101010110010101111010 |

- Relational Less Than \< a b a \< b -1 0 true 0 0 false +1 0 false

- Greater Than \> a b a \> b -1 0 false 0 0 false +1 0 true

- Less Than Or Equal \<= a b a \<= b -1 0 true 0 0 true +1 0 false

- Greater Than or Equal \>= a b a \>= b -1 0 false 0 0 true +1 0 true

- Equality Equal == a b a == b -1 0 false 0 0 true +1 0 false

- Not Equal != a b a != b -1 0 true 0 0 false +1 0 true

- Approximately Equal \~~ this operator rounds both sides to integer
  numbers before comaring. It is especially to support betsize and
  stacksize comparisons of converted PPL profiles, as Shanky PPL works
  with integers only.

- Bitwise AND & Logical AND operation on a bit by bit basis.  

  | expression |              binary              |
  |:----------:|:--------------------------------:|
  |     a      | 11001001011101010110010101111010 |
  |     b      | 01001010010100101110001010101111 |
  |    a&b     | 01001000010100000110000000101010 |

- Bitwise OR \| Logical OR operation on a bit by bit basis.  

  | expression |              binary              |
  |:----------:|:--------------------------------:|
  |     a      | 11001001011101010110010101111010 |
  |     b      | 01001010010100101110001010101111 |
  |   a \| b   | 11001011011101111110011111111111 |

- Bitwise XOR ^ Logical XOR operation on a bit by bit basis.  

  | expression |              binary              |
  |:----------:|:--------------------------------:|
  |     a      | 11001001011101010110010101111010 |
  |     b      | 01001010010100101110001010101111 |
  |    a^b     | 10000011001001111000011111010101 |

- Logical AND && False when any operand is false. True when both
  operands are true.  

  |   a   |   b   | a && b |
  |:-----:|:-----:|:------:|
  | false | false | false  |
  | false | true  | false  |
  | true  | false | false  |
  | true  | true  |  true  |

- Logical XOR ^^ (not ANSI-C) False when operands are boolean equal.
  True when operands are not boolean equal. Note that a^^b is equivalent
  to (a!=0)^(b!=0).  

  |   a   |   b   | a ^^ b |
  |:-----:|:-----:|:------:|
  | false | false | false  |
  | false | true  |  true  |
  | true  | false |  true  |
  | true  | true  | false  |

- Logical OR \|\| False when both operands are false. True when any
  operand is true.  

  |   a   |   b   | a \|\| b |
  |:-----:|:-----:|:--------:|
  | false | false |  false   |
  | false | true  |   true   |
  | true  | false |   true   |
  | true  | true  |   true   |

- Conditional ?: Standard algorithmic if then else. a ? b : c means If a
  then b else c.  

  |   a   |  b  |  c  | a ? b : c |
  |:-----:|:---:|:---:|:---------:|
  | true  | any | any |     b     |
  | false | any | any |     c     |

- Grouping Operators ()\[\]{} Note that \[\] and {} are not ANSI-C.
  These grouping operators are used to either visibly separate sections
  of your code for readability and maintainability purposes, or to
  affect the precedence of logical operation. Note that unlike
  WinHoldem’s grouping syntax, there is no limitation on how the various
  grouping operators can be nested.

## Numeric Constants Floating point constants

All numeric constants are treated internally as double floating point
values in base 2. Floating Point Numeric Constants 123.456 0.987
192837465 .5 17. 5.4321e-76

Integer constants There are 4 integer options available as well that
allow you to select the base of the constant. The 4 available bases are:
16, 8, 4, 2. Prefixing a numeric constant with a zero followed by a
letter (see table below) will specify the numeric base of the constant.

Letter Base Name x 16 Hex o 8 Octal (non-standard ANSI C) q 4 Quadal
(non-standard ANSI C) b 2 Binary (non-standard ANSI C)

Examples:

| Decimal | Hex  | Octal | Quadal | Binary     |
|:--------|:-----|:------|:-------|:-----------|
|         | 0x0  | 0o0   | 0q0    | 0b0        |
|         | 0x1  | 0o1   | 0q1    | 0b1        |
|         | 0x2  | 0o2   | 0q2    | 0b10       |
|         | 0x3  | 0o3   | 0q3    | 0b11       |
|         | 0x4  | 0o4   | 0q10   | 0b100      |
|         | 0x5  | 0o5   | 0q11   | 0b101      |
|         | 0x6  | 0o6   | 0q12   | 0b110      |
|         | 0x7  | 0o7   | 0q13   | 0b111      |
|         | 0x8  | 0o10  | 0q20   | 0b1000     |
|         | 0x9  | 0o11  | 0q21   | 0b1001     |
|         | 0xA  | 0o12  | 0q22   | 0b1010     |
|         | 0xB  | 0o13  | 0q23   | 0b1011     |
|         | 0xC  | 0o14  | 0q30   | 0b1100     |
|         | 0xD  | 0o15  | 0q31   | 0b1101     |
|         | 0xE  | 0o16  | 0q32   | 0b1110     |
|         | 0xF  | 0o17  | 0q33   | 0b1111     |
|         | 0x10 | 0o20  | 0q100  | 0b10000    |
|         | 0x1F | 0o37  | 0q133  | 0b11111    |
|         | 0x7F | 0o177 | 0q1333 | 0b1111111  |
|         | 0xFF | 0o377 | 0q3333 | 0b11111111 |
