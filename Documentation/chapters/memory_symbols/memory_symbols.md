# Memory Symbols 

## Introduction 

One of the most powerful features of OpenHoldem is its ability to
remember. Very few other bots have this ability.

## Planning 

Working with memory symbols requires a bit of planning and specifically
one should keep the following in mind: OpenHoldem does not know your
memory symbol before you create it. This sounds simple but one should
not forget it because it could create problems with your first hand (The
symbol would be undefined and return 0). Once a memory symbol is
created, and a value is stored, OpenHoldem will remember that value
until it is altered or replaced by another or until OpenHoldem is
closed. This is great if you want OpenHoldem to remember what happened
10 hands ago but could bite you if you forget to reset them. It is of
utmost importance to decide when and what should be remembered.

## Formulation 

OpenHoldem provides memory_symbols to store values in variables in your
formulas as a replacement for left-hand-side-expressions. Storing a
value looks like me_st_SYMBOLNAME_VALUE. For example you can store:

<b>numbers</b>, e.g. me_st_Pi_3_141

<b>symbols</b>, e.g. me_st_MyChair_userchair

<b>functions</b>, e.g. me_st_CallFunction_f\$call

<b>memory</b> symbols, e.g. me_st_OldValue_me_re_CurrentValue

me_st\_ will store a new value, where_as me_re\_ will lookup a
previously stored value and me_inc\_ will increment a value that serves
as a counter. OpenHoldem memory-symbols will never reset as long as you
don’t explicitly do so. Don’t confuse this behaviour with OpenPPL that
resets all user-variables at the beginning of a new hand. A technical
note: the desired result of a me_st_command is its side-effect; the
symbol itself will be evaluated as 0.

## Ini-functions

All memory-symbols have to be cleared or initialized at some time. To do
this in a clean and fail-safe way OpenHoldem provides six
initialization-functions since version 4.2.0. They get called at various
times of execution, but always after the basic symbols have been
calculated and before the autoplayer-functions get evaluated. Due to our
verbosity-fetish they should be pretty self-explaning:

- f\$ini_function_on_startup

- f\$ini_function_on_connection

- f\$ini_function_on_handreset

- f\$ini_function_on_new_round

- f\$ini_function_on_my_turn

- f\$ini_function_on_heartbeat

Simple example:

    ##f$ini_function_on_my_turn##
    f$MonsterHand ? me_st_GoodSlowPlaySituation_1 : 0

## Putting it together

To make things clear we will be putting two memory symbols into your
bot. A) We will create a “Stack to Pot Ratio” memory symbol (the
function of this symbol is to store the ratio of our balance to the pot
at the start of the betting on the flop to be retrieve later in order to
make commitment decisions), and B) We will create a “Slow Play” memory
symbol, (the function of this symbol is to store our decision during a
betting round that we will check-raise the next betting round regardless
of what the next card is)

### STEP 1: Create the symbols:

In f\$ini_function_on_handreset we put:

      me_st_stpr_0 
    + me_st_slowplay_0

to reset these two values on handreset to zero (which means false in the
second case).

### STEP 2 (a): 

In f\$ini_function_on_my_turn we put

    betround == 2 ?
    (me_st_stpr_f$stpr + me_st_slowplay_f$slowplay) : 0

If it is on the flop then we will store the values of the functions
f\$stpr and f\$slowplay at that moment.

### STEP 2(b) 

We create the functions whose value we want to store:

    ##f$stpr## 
    balance/potcommon 

Comment: we don’t use “pot” because that would include any bets during
round2 before us.

    ##f$slowplay##
    betround==2 && nhandshi==0 ? 1 : 0 

Comment: this formula will return 1 when we have the nuts and this will
be stored into the “slowplay” memory symbol

### STEP 3 Retrieve and use the memory. 

In f\$allin we put

    betround==3 && me_re_slowplay && me_re_stpr<10 ? 1 : 0 

English translation: It is the turn and we, on the flop, decided to slow
play and the ratio between the pot (at the start of betround==2) and our
balance at that time was 1:10 and therefore we will shove.

## Conclusion 

The memory symbols are very powerful but need a bit of planning. It is
important to decide when to define, store and retrieve the values in
these symbols.
