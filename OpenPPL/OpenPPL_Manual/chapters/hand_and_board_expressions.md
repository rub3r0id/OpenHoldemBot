# Hand And Board Expressions

## Hand expressions

One of the most important decisions of the game happens preflop: shall I
play this hand and how? This decision can be coded with the
self-explanatory hand-expression, like in the example below:

    WHEN hand$AA RaiseMax FORCE
    WHEN hand$AQSuited OR hand$AJSuited RaiseTo 3 FORCE
    WHEN hand$22 OR hand$33 OR hand$44... Call FORCE

<div class="rem*">

* 1*. AK does include both AKs and AKo. So if you want to play suited
hands differently you should code them first, as OpenPPL gets evaluated
top down. It will stop at the first condition that matches (evaluates to
true). So always remember: *strong hands first, exceptions first, bad
hands later.*

</div>

## Coding For Specific Suits

If you want you can also code for specific suits, like an ace of
diamonds in your hand. This is rarely necessary, but was used in the
past (before real randomization was introduced to Standard PPL) to
randomize actions.

    WHEN hand$AcQd Or hand$JhTs ...
    // Randomize your Action, the old way
    WHEN hand$AdT RaiseTo 10 FORCE
    WHEN hand$AT Call FORCE

But be careful with the code below:

    WHEN hand$AKs...

It means: any ace and king of spades, but not AK suited

## Board Expressions

A lot of the game also depends on the board cards. There are symbols
like “HaveStraightDraw” or “FlushPossibleOnTurn“, but for some cases
might not be concrete enough. Therefore it is possible to specify
board-states similar to the above:

    // Calling, if any ace is on the board
    WHEN board$A Call FORCE
    // Raising, if there is a low pair on board
    WHEN board$22 OR board$33 OR board$44... RaiseTo 10 FORCE
    // Raising, if there are A and T of the same suit
    WHEN board$AT SUITED RaisePot FORCE

You see, this is pretty straightforward, but sometimes lots of code to
write. If you want to create code that is easy to understand, easy to
reuse and easy to maintain, then you should encapsulate expressions like
the second one in functions (place it within its own function):

    ##f$LowPairOnBoard##
        WHEN board$22 OR board$33 OR board$44... RETURN TRUE

User-defined variables would also be possible, but they are not nearly
as good as functions.
