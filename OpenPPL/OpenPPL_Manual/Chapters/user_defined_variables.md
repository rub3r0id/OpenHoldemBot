# User-Defined Variables

Most probably you need some game-history to take your decision; then you
will find symbols like NoBettingOnFlop and OpenHoldem’s history symbols
and they will be useful for a good portion os use-cases, but identifying
very special situations afterwards only with the built-in symbols might
be hard or even impossible. So wouldn’t it be helpful if you could
remember what happened in the game? Of course you can - with
user-defined variables. Let’s take a small example.

*User-defined variables need to be prefixed with the word “user”, and
the word Set when you give them a value.*

    WHEN FirstCallerPosition = 9 Set user_UTG_Was_Limping

- As you see, there’s the **Set** command and after it there is a
  user-defined variable instead of an action after a condition, but no
  keyword force.

- Whenever OpenPPL / OpenHoldem sees such a construct it evaluates the
  when-condition. If the condition is true, OpenHoldem sets the
  user-variable to true and continues with the evaluation, until it
  finds a true condition with an action.

- All user-defined variables start with false (0). Once you set them
  they become true (or 1, which is technically the same).

- User-defined variables keep their value for the current hand and can’t
  be reset back by the user. But when the hand is over they get reset
  automatically.

- Naming: every user-defined variable starts with the prefix “user”,
  followed by a sequence of characters \[a-zA-Z\], digits \[0-9\] and
  underscores \[\_\].

- Querying the value of a variable is simple: you can use it just like
  any other symbol as part of an expression:

      ##f$preflop##
          WHEN Hand$AA RaiseMax FORCE 
          WHEN Hand$KK Set userDoesNotKnowWhatToDo 
          WHEN Hand$QQ Set userStartsToCry 
          WHEN userDoesNotKnowWhatToDo Call FORCE 
          WHEN userStartsToCry SitOut FORCE 
          WHEN Others Fold FORCE

## Expert Tricks (Memory Symbols)

Do you need variables that can be set to any arbitrary value? Do you
need variables that can be reset back? Do you need variables that don’t
reset automatically, but keep their values till the next hand or even
for the complete session? There is a solution for it (of course).
Instead of PPL-like user-variables it is also possible to use
OpenHoldem’s memory-store-command (following example store the decimal
number 3,14..):

    WHEN (...) Set me_st_MySecretVariable_3_141592653

and then use it later with OpenHoldem’s memory-recall-command:

    WHEN (... me_re_MySecretVariable ...) ...

This construct is a little bit more mighty, but also contains some
possible pitfalls and requires extra care by the user.

- OpenHoldem’s user-defined variables are case sensitive. me_st_x_1 is
  something different than me_st_X_1.

- No underscores allowed in the name of the variable. Underscores are
  used to separate name and value. (If you wonder, why underscores are
  allowed in simple user-variables: because the translator removes
  them).

- No automatic reset. If you need such a reset, you could do it e.g.
  before your first action preflop:

      ##f$preflop##
      WHEN (BotsActionsOnThisRound = 0)
          WHEN Others Set me_st_MySecretVariable_0
          ...

- Table occlusion reset the memory variables.

*May the force be with you!*
