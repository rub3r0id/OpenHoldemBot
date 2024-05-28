# Structure Of A PPL-File

If you have used OpenHoldem in the past you will know that you have to
answer several questions: Shall I go allin? Shall I raise? Shall I call?
And if you answer all questions with no then OpenHoldem will fold. That
is one approach and it clearly has some pros. But most poker-playing
people and non-programers will find a different approach more easy:
*What shall I do in this situation?* And that’s exactly how OpenPPL
works.

## Simple When Conditions With Actions

The most simple way to code a bot consists of a series of conditions
followed by actions to be chosen.

    WHEN HaveFlushDraw AND AmountToCall < 1/3 PotSize Call FORCE

These conditions are *always evaluated top-down*. Once the first
condition is true, the appropriate action will be taken. Always! - so
the order of programming matters. Let’s assume, that you want to call
your flushdraws, but raise to 10bb your nut-flushdraws (expert-strategy
2012). Then you will have to write your commands in the following order:

    WHEN HaveNutFlushDraw RaiseTo 10 FORCE
    WHEN HaveFlushDraw Call FORCE

Do it the other way and your nut-flush-draw would trigger the rule for
normal flush-draws. A call would be the result. As a consequence of this
top-down-evaluation we recommend you deal with:

- *strong hands first, special cases first*

- *weak hands last, general cases last*

The bot simply does not know if one rule is “more special” or “more
important” — you have to tell it by your coding order.

<div class="rem*">

* 0.1*. If you wonder about the keyword
<span class="smallcaps">force</span>: it was inherited from Shanky-PPL
and means, that it overwrites the default bot (without
<span class="smallcaps">Force).</span> Though we don’t provide a default
bot and don’t think, that user-defined actions should be ignored if they
lack the FORCE, we kept this keyword to stay compatible and because it
is nice to read (syntactical sugar).

</div>

## Open-Ended When Conditions

Programming your bot with when-conditions alone will — in principle — do
the job, but there will be lots of situations that are very similar.

    WHEN hand$AT AND StillToAct = 2 AND Raises = 1 AND AmountToCall <= 4 RaisePot FORCE
    WHEN hand$AT AND StillToAct = 2 AND Raises = 1 AND AmountToCall > 4  Fold FORCE
    WHEN hand$AT AND StillToAct = 2 AND Raises = 2 ...

Here one part of the condition gets repeated:

    WHEN hand$AT AND StillToAct = 2

For more sophisticated profiles this would be lots of code to write,
lots of code to evaluate and a true nightmare to change once you want to
improve it. So OpenPPL provides two kinds of conditions: top-level
conditions without actions (called “open-ended when-conditions”) and
simple “when conditions with actions” like explained above.

Once the first open-ended-when-condition is located all following
“normal” when-conditions are bound to that condition and only evaluated
when the open-ended when-condition is true. So you could rewrite the
example above like that:

    WHEN hand$AT AND StillToAct = 2
        WHEN Raises = 1 AND AmountToCall <= 4 RaisePot FORCE
        WHEN Raises = 1 AND AmountToCall > 4 Fold FORCE
        WHEN Raises = 2 ...
    WHEN hand$A9 AND StillToAct = 2
        ...

Each open-ended when-condition is active until the next open-ended
when-condition is found. In the example above:

    WHEN hand$A9 AND StillToAct = 2

To terminate all your open-ended when-conditions just write:

    When Others
        ...
        When Others Fold Force

Coding this way makes your code smaller, more easy to read and more easy
to change. However: some people would like to take code-structuring to
extremes and use multiple nested open-ended when-conditions like below:

    WHEN hand$AT
        WHEN StillToAct = 2
            WHEN Raises = 1
                WHEN (AmountToCall <= 4) RaisePot FORCE
                WHEN (AmountToCall > 4) Fold FORCE
            WHEN Raises = 2
                WHEN...

In principle this is a good idea, but it does not work. Simply because
there is no way to tell, where one open-ended when-condition ends and
where the next one starts. So the semantics would be completely
undefined (it is in fact not, but it is for sure not what you want).
Sure you could argue about indentation, but spaces have no meaning in
most programming languages (except good old Fortran 77) and everybody
does it differently. So let’s restate: There is *at most one level of
open-ended when-conditions* (without action), each one bound to a
sequence of when-conditions with actions. If you want to structure your
code even more (a very good idea!) then we recommend to look at the
chapter “Building Symbols On Your Own”.

## Controlflow of Open-Ended When-Conditions

<figure>
<img src="images/when_conditions_control_flow.png" />
</figure>

## Structure Of A PPL-File

Once you understand how when-conditions work, programming your first bot
becomes easy and straightforward: you just have to provide a sequence of
when-conditions for Preflop, Flop, Turn and River. These 4 main
code-sections are named f\$preflop..f\$river, because that’s how
user-defined OpenHoldem symbols get named and from a technical point of
view these code-sections are functions.

    ##f$preflop##
        // This is a comment
        // Your code belongs here.
        WHEN hand$AA RaiseMax FORCE 
        WHEN hand$KK ...
        ...
        WHEN Others Fold FORCE

    ##f$flop##

    ##f$turn##

    ##f$river##

## Unspecified Return Values

People who create complete profiles usually add

    WHEN Others
       WHEN Others Fold FORCE

to the end of every code-section. But it does not hurt if you don’t so.
If no condition matches the situation OpenHoldem will automatically
continue to evaluate the built-in default-not (Gecko). If no default-bot
is present (you may safely delete it) then OpenHoldem will evaluate
functions without a return-value to zero, which is also the encoding for
false, and also for check/fold.

## More Advanced Coding

Coding sequences of when-conditions is very easy and intuitive, however
there is one big disadvantage: poker is a somewhat complex game and
there are countless situations to consider. So these code-blocks can
become rather large – too large for a sane human mind. But of course
there is a solution: OpenPPL supports structured coding, namely:

- user-defined hand-lists

- user-defined symbols, i.e. named functions, that get defined once and
  can be used at multiple places.

Both of them are very useful, but a little bit “advanced” and not
standard Shanky-PPL. So we discuss them in later chapters of this
manual.
