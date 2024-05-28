# Mathematical Expressions

Of course OpenPPL supports arbitary complex mathematical expressions. As
an example let us consider odds and outs.

```c
    // Calling according to odds and outs
    WHEN AmountToCall / (AmountToCall + PotSize) > Outs / CardsLeft Call FORCE
```

Off course this example is a bit simplistic. It does not consider other
players in the pot, implied odds on future streets, the chance to
semi-bluff, etc. But I think you get the point.

The following operators are supported:

## Equality Operators

| Operator | Meaning | Example | Example explained |
|:---|:---|:---|:---|
| = | equal | StillToAct = 2 | true, if you are on the button |
| != | not equal | Position != First | true, if you are not out of position |
| \< | smaller | AmountToCall \< 5 | true, if there are less than 5 big blinds to call |
| \> | larger | PotSize \> 20 | true, if the pot is larger than 20 big blinds |
| \<= | smaller or equal | AmountToCall \<= 5 | true, if there are less than or equal to 5 big blinds to call |
| \>= | larger or equal | PotSize \>= 20 | true, if the pot contains 20 or more big blinds |

## Logical Operators

The logical operators “and”, “or”, and “not” should be pretty
self-explanatory.

| Operator | Example |
|:---|:---|
| Not | WHEN (HaveNothing AND OpponentsLeft \>= 2 AND NOT BotIsLastRaiser) Check FORCE |
| And | WHEN (BotIsLastRaiser AND OpponentsLeft = 1 AND Bets = 0 And ... BetHalfPot FORCE) |
| XOr | Meaning: either or, which is true, if exactly one of the operands is true, but not both |
|  | WHEN (hand\$AA OR hand\$KK) RaiseMax FORCE |

Negation (Not) has highest priority of all operators, thereafter follow
And, XOr and OR in decreasing order. So if you want to write an
expression like

    WHEN AmountToCall <= 4 AND (hand$22 OR hand$33...))

you have to throw in some extra brackets, otherwise the bot will call
with 33 any bet and that is probably not what you want. More complicated
expressions sometimes lead to confusion. If you have a problem with that
you might want to revisit the basics of mathematical logic and the “Laws
of De Morgan”.

## Arithmetical Operators

OpenPPL also supports basic arithmetic. The usual rules apply of course.
The percentage-operator has the same priority like multiplication and
division, which is higher than addition, subtraction.

| Operator | Meaning | Example |
|:---|:---|:---|
| \+ | addition |  |
| \- | subtraction |  |
| \* | multiplication |  |
| / | division |  |
| % | Percentage-operator | WHEN (AmountToCall \<= 50% PotSize) Call FORCE |
| Mod | Modulus-operator |  |

## Bitwise Operators (for Experts)

Furthermore OpenPPL supports bitwise operations that work on all single
bits of bit-vectors or binary numbers simultaneously. They are useful
for very low-level-stuff like detecting which chairs are seated with
OpenHoldem’s bitwise symbols (playersseatedbits, playersdealtbits,
etc.). Most players won’t ever need these symbols, so we will only give
you a link to a good explanation here:
<http://en.wikipedia.org/wiki/Bitwise_operation>

| Operator |
|:---------|
| BitAnd   |
| BitCount |
| BitNot   |
| BitOr    |
| BitXOr   |
